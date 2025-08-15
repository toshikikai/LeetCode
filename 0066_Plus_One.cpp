#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

    }
};

int main() {
    Solution sol;
    string input;

    // Automatically reads test cases from input.txt
    while (getline(cin, input)) {
        if (!input.empty()) {
            cout << sol.plusOne(input) << endl;
        }
    }

    return 0;
}
