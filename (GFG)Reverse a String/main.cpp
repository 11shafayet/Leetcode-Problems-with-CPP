//https://www.geeksforgeeks.org/problems/java-reverse-a-string0416/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string revStr(string s) {
        long long n = s.length();
        
        for(long long i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i -1]);
        }
        
        return s;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.revStr(s) << endl;
        cout << "~" << endl;
    }
    return 0;
}