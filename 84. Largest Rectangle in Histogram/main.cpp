// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // Dummy bar
        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()]; st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxi = max(maxi, height * width);
            }
            st.push(i);
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        int result = sol.largestRectangleArea(heights);
        cout  << result << "\n";
    }

    return 0;
}
