// https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       // brute force approach : 
        // find all permutations,
        // search for our permutation
        // return the next one

        ////////////// optimal approach ////////////////////////
        int pivot = -1, n = nums.size();

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
         // reverse(nums.begin() + pivot + 1, nums.end());

        int i = pivot + 1, j = n - 1;
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
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
    solution.nextPermutation(nums);

    cout << "Next permutation: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
