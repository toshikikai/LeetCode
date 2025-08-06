-- Cheat Engine Lua script: Select an item once, set its quantity 100 times
if syntaxcheck then return end
[ENABLE]

local List = getAddress("pPersistent")
local _Names = getAddress("ItemNames")
local pItemReference = getAddress("ItemReference")

if readPointer(List) == 0 then
    print("Error: Load A SaveGame First To Init The Items")
    error("no items")
    return
end
writeBytes(getAddress("bStop"),1)

-- Sorts and deduplicates item names
default function NoRestForTheWicked_TableFix ( Table )
    if not Table then return end
    table.sort( Table, function( NameStruct_1, NameStruct_2) return NameStruct_1.Name < NameStruct_2.Name end )
    local SeenNames = {}
    local Result = {}
    for Index, NameStruct in pairs( Table ) do
        local Base = NameStruct.Name
        local i = 1
        while SeenNames[NameStruct.Name] do
            NameStruct.Name = Base .. "_" .. i
            i = i + 1
        end
        SeenNames[NameStruct.Name] = true
        Result[Index] = NameStruct
    end
    return Result
end

-- Reads all item names and references from memory
default function NoRestForTheWicked_ItemTable ( )
    local Names = {}
    local Index = 0
    local EntityRef = readQword( List )

    while EntityRef ~= 0 do
        local pStr = readPointer ( _Names + Index )
        local Name = readString( pStr + 0x14, 256, true )
        Names[#Names+1] = { Name = Name, EntityRef = EntityRef }
        Index = Index + 0x8

        -- fail safe
        if Index >= 0x10000 then
            break
        end

        EntityRef = readQword( List + Index )
    end
    return Names
end

-- Build the item name list and prompt user to select one
local NameList = createStringList()
local Sorted_NameTable = NoRestForTheWicked_TableFix( NoRestForTheWicked_ItemTable( ) )
if Sorted_NameTable then
    for Index, NameStruct in pairs( Sorted_NameTable ) do
        NameList.add( NameStruct.Name )
    end
end

local Index, Name = showSelectionList( "Select A Item Name", "Select:", NameList, false )
if Index == -1 then
    error "No Selection" return
end

-- Set the item reference
writeQword( pItemReference, Sorted_NameTable[Index+1].EntityRef )

-- Set the quantity of the selected item 100 times
local desired_quantity = 99  -- Change this to your desired quantity
local item_address = Sorted_NameTable[Index+1].EntityRef
local quantity_offset = 0x20 -- <<<< Replace this with the correct offset for quantity

for i = 1, 100 do
    writeInteger(item_address + quantity_offset, desired_quantity)
end

[DISABLE]