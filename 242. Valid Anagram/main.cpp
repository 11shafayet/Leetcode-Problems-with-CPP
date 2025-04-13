// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> count; 

        for(char c : s) {
            count[c]++;
        }

        for(char c : t) {
            if(!count[c]) return false;
            else count[c]--;
        }

        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
  
        Solution ob;
        cout << ob.isAnagram(s,t) << endl;

        cout << "~" << endl;
    }
    return 0;
}