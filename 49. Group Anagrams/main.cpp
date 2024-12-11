// https://leetcode.com/problems/group-anagrams/description/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;

        for (string s : strs) {
            string newStr = s;
            sort(newStr.begin(), newStr.end());
            myMap[newStr].push_back(s);
        }

        vector<vector<string>> result;
        for (auto item : myMap) {
            result.push_back(item.second);
        }

        return result;
    }
};

int main() {
    vector<string> strs;
    string word;
    while (cin >> word) {
        strs.push_back(word);
    }

    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(strs);

    for (const auto& group : result) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i];
            if (i < group.size() - 1) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
