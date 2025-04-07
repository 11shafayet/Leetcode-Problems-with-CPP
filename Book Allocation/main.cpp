//https://www.naukri.com/code360/problems/allocate-books_1090540

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& nums, int n, int m, int maxNum) {
        int std = 1, pages = 0;

        for(int num:nums) {
            if(num > maxNum) return false;

            if(pages + num <= maxNum) {
                pages += num;
            } else{
                std++;
                pages = num;
            }
        }

        return std <= m;
        
        
    }

    int findPages(vector<int>& nums, int n, int m) {
        if(m > n) return -1;

        int low = INT_MIN, high = 0, ans = -1;

        for(int num : nums) {
            low = max(low, num);
            high+= num;
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isValid(nums, n, m, mid)) {
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
        cout << ob.findPages(nums, nums.size(), m) << endl;

        cout << "~" << endl;
    }
    return 0;
}