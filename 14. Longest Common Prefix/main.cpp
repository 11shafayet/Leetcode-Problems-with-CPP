// https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans = strs[0];

        for(int j = 1; j < strs.size(); j++) {
            int i = 0;

            while(i < ans.length() && i < strs[j].length() && ans[i] == strs[j][i]) {
                i++;
            }

            ans = ans.substr(0, i);
            if(ans.empty()) return ans;
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; // number of strings in the vector
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
        }

        Solution ob;
        cout << ob.longestCommonPrefix(strs) << endl;
        cout << "~" << endl;
    }
    return 0;
}
