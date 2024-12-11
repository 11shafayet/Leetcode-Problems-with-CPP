// https://leetcode.com/problems/longest-repeating-character-replacement/description/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxCount = 0, start = 0, result = 0;
        unordered_map<char, int> charCount;

        for (int end = 0; end < n; ++end) {
            charCount[s[end]]++;
            maxCount = max(maxCount, charCount[s[end]]);

            while ((end - start + 1) - maxCount > k) {
                charCount[s[start]]--;
                start++;
            }

            result = max(result, (end - start + 1));
        }

        return result;
    }
};

int main() {
    string s;
    int k;
    
    cin >> s;
    cin >> k;

    Solution solution;
    int result = solution.characterReplacement(s, k);

    cout << result << endl;

    return 0;
}
