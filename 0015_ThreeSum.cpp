class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int left = i + 1;
                int right = nums.size() - 1;
                int sum = 0 - nums[i];
                while (left < right)
                {
                    if (nums[left] + nums[right] == sum)
                    {
                        vector<int> tp;
                        tp.push_back(nums[i]);
                        tp.push_back(nums[left]);
                        tp.push_back(nums[right]);
                        res.push_back(tp);

                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    else if (nums[left] + nums[right] < sum)
                        left++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
};