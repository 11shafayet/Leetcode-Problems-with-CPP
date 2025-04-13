//https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sizeOfNums = nums.size();
        int result = -1;

        int leftIndex = 0;
        int rightIndex = sizeOfNums - 1;

        while(leftIndex <= rightIndex) {
            int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
            if(nums[middleIndex] == target) {
                result = middleIndex;
                break;
            }

            // check if the left half is sorted
            if(nums[middleIndex] >= nums[leftIndex]) {
                if(target >= nums[leftIndex] && target < nums[middleIndex]) {
                    rightIndex = middleIndex - 1;
                } else {
                    leftIndex = middleIndex + 1;
                }
            } else {
                if(target <= nums[rightIndex] && target > nums[middleIndex]) {
                    leftIndex = middleIndex + 1;
                } else {
                    rightIndex = middleIndex - 1;
                }
            }
        }

        return result;
    }
};

int main() {
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> target;

    Solution solution;
    int result = solution.search(nums, target);

    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
