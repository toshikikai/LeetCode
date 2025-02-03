class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int mx = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            int vol = (right - left) * (min(height[left], height[right]));
            mx = max(vol, mx);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return mx;
    }
};