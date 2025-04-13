// https://leetcode.com/problems/rotate-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        return (s+s).find(goal) != string::npos;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
  
        Solution ob;
        cout << ob.rotateString(s,t) << endl;

        cout << "~" << endl;
    }
    return 0;
}