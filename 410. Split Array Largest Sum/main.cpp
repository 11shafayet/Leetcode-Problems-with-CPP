// https://leetcode.com/problems/split-array-largest-sum/description/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& nums, int n, int k, int maxSum) {
        int split = 1, sum = 0;
        for(int num : nums) {
            if(num > maxSum) return false;

            if(sum + num > maxSum) {
                split++;
                sum = num;
            } else 
                sum += num;

        }
        return split <= k;                
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;

        int low = INT_MIN, high = 0, ans = -1;

        for(int num : nums) {
            low = max(low, num);
            high += num;
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isValid(nums, n, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> nums;
        int n, m;
        cin >> n >> m;

        while(n--) {
            int x;
            cin >> x;
            nums.push_back(x); 
        }
        Solution ob;
        cout << ob.splitArray(nums, m) << endl;

        cout << "~" << endl;
    }
    return 0;
}