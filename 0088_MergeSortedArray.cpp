// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> res;
//         int i=0,j=0;
//         while(i<m && j<n) {
//             if(nums1[i]<=nums2[j]) res.push_back(nums1[i++]);
//             else res.push_back(nums2[j++]);
//         }
//         while(i<m) {res.push_back(nums1[i++]);}
//         while(j<n) {res.push_back(nums2[j++]);}
//         nums1=res;
//     }
// };

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0)
        {
            if (i >= 0 && nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};