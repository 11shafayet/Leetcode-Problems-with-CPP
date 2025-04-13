// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, count = 0;

        for(auto c : s) {
            if(c == '(') {
                count++;
                ans = max(ans, count);
            } else if(c == ')') {
                count--;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
  
        Solution ob;
        cout << ob.maxDepth(s) << endl;

        cout << "~" << endl;
    }
    return 0;
}