// https://leetcode.com/problems/sliding-window-maximum/description/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for(int i = 0; i < nums.size(); i++) {
            // Remove out-of-window indices
            if(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Maintain decreasing order
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Store result after first window is formed
            if(i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> k;

    Solution sol;
    vector<int> res = sol.maxSlidingWindow(nums, k);

    for(int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
