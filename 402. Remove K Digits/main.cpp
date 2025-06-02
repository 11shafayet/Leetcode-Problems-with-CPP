// https://leetcode.com/problems/remove-k-digits/description/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;

        for(char digit : num) {
            while(!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            
            st.push(digit);
        }

        while(k-- && !st.empty()) {
            st.pop();
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.length() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        string num;
        int k;
        cin >> num >> k;

        Solution sol;
        string result = sol.removeKdigits(num, k);
        cout << "Result: " << result << endl;
    }

    return 0;
}

