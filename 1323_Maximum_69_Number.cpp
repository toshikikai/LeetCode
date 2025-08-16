#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        int pwr = 4, res = 0;
        bool found = false;
        while (pwr >= 0)
        {
            int dig = num / (int)(pow(10, pwr));
            if (dig == 0)
            {
                pwr--;
                continue;
            }
            if (dig == 6 && !found)
            {
                dig = 9;
                found = true;
            }
            res = res * 10 + dig;
            // cout << "Current digit: " << dig << ", Power: " << pwr << ", Res: " << res << endl;
            num = num % (int)(pow(10, pwr));
            pwr--;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int testCases;

    // Read number of test cases
    cin >> testCases;
    cin.ignore(); // Clear the newline after reading testCases

    // Process each test case
    for (int t = 0; t < testCases; t++)
    {
        int input;
        cin >> input;

        cout << sol.maximum69Number(input) << endl;
    }

    return 0;
}
