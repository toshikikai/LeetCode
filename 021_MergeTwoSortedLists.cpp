// Iterative
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *st = new ListNode(0);
        ListNode *res = st;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                res->next = list1;
                list1 = list1->next;
            }
            else
            {
                res->next = list2;
                list2 = list2->next;
            }
            res = res->next;
        }
        res->next = list1 ? list1 : list2;
        return st->next;
    }
};

// Recursive
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 || !list2)
        {
            return list1 ? list1 : list2;
        }
        if (list1->val > list2->val)
            swap(list1, list2);
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};