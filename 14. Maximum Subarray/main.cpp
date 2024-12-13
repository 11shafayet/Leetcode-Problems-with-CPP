
// https://leetcode.com/problems/maximum-subarray/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /////////////////////// Brute Force Approach /////////////////////////////

        // int n = nums.size();
        // int maxSum = INT_MIN;

        // for(int i = 0; i < n; i++) {
        //     int currentSum = 0;
        //     for(int j = i; j < n; j++) {
        //         currentSum += nums[j];
        //         maxSum = max(currentSum, maxSum);
        //     }
        // }

        // return maxSum;


        ///////////////////// With Kadane's Algo ///////////////////////////////////
        int n = nums.size();
        int currentSum = 0;
        int maxSum = INT_MIN;

        for(int num : nums) {
            currentSum += num;
            maxSum = max(currentSum, maxSum);
            if(currentSum < 0) currentSum = 0;
        }

        return maxSum;
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    int result = solution.maxSubArray(nums);

    cout << "Maximum sum of subarray: " << result << endl;

    return 0;
}

