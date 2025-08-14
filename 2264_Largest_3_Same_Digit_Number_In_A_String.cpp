#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int i = 0;
        string retStr = "";

        while (i < num.length() - 2) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string current = num.substr(i, 3);
                if (retStr.empty() || current > retStr) {
                    retStr = current;
                }
                i += 3;
            } else {
                i++;
            }
        }

        return retStr;
    }
};

int main() {
    Solution sol;
    string num;

    // Read test cases from input.txt
    while (getline(cin, num)) {
        if (!num.empty()) {
            cout << sol.largestGoodInteger(num) << endl;
        }
    }

    return 0;
}
