#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        vector<int> last(32, -1); // last position where bit j is set

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    last[b] = i;
                }
            }
            int maxRight = i;
            for (int b = 0; b < 32; ++b) {
                if (last[b] != -1) {
                    maxRight = max(maxRight, last[b]);
                }
            }
            answer[i] = maxRight - i + 1;
        }
        return answer;
    }
};