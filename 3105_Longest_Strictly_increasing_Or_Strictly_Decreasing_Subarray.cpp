class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int inidx = 0, dcidx = 0, inl = 1, dcl = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                inl = max(i - inidx + 1, inl);
            }
            else
            {
                inidx = i;
            }
            if (nums[i] < nums[i - 1])
            {
                dcl = max(i - dcidx + 1, dcl);
            }
            else
            {
                dcidx = i;
            }
        }
        return max(inl, dcl);
    }
};