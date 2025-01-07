class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++) {
            int req=target-nums[i];
            if(hash.find(req)!=hash.end()) {
                return {hash[req],i};
            }
            hash[nums[i]]=i;
        }  
        return {};     
    }
};