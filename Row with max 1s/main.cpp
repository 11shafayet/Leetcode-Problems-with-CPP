// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
  public:
    //////////////// BRUTE FORCE APPROACH ///////////////////////////   
    // int rowWithMax1s(vector<vector<int>> &nums) {
    //     int rows = nums.size(), cols = nums[0].size(), count = 0, ans = -1;
        
    //     for(int i = 0; i < rows; i++) {
    //         int inCount = 0;
    //         for(int j = 0; j < cols; j++) {
    //             if(nums[i][j] == 1) inCount++;
    //         }
            
    //         if(inCount != 0 && inCount > count) {
    //             count = inCount;
    //             ans = i;
    //         }
    //     }
        
    //     return ans;
    // }
    
    
    
    //////////////// BINARAY SEARCH APPROACH /////////////////////////// 
    // int eachCount(vector<int> nums) {
    //     int low = 0, high = nums.size() - 1;
        
    //     while(low <= high) {
    //         int mid = low + (high - low) / 2;
            
    //         if(nums[mid] == 1) high = mid - 1;
    //         else low = mid + 1;
    //     }
        
    //     return nums.size() - low;
    // }
    // int rowWithMax1s(vector<vector<int>> &nums) {
    //     int rows = nums.size(), cols = nums[0].size(), maxCount = -1, index = -1;
        
    //     for(int i = 0; i < rows; i++) {
    //         int count = eachCount(nums[i]);
            
    //         if(count != 0 && count > maxCount) {
    //             index = i;
    //             maxCount = count;
    //         }
    //     }
        
    //     return index;
    // }    
    
    
    //////////////// OPTIMAL APPROACH /////////////////////////// 
    int rowWithMax1s(vector<vector<int>> &nums) {
        if (nums.empty() || nums[0].empty()) return -1;
        int rows = nums.size(), cols = nums[0].size(), R = 0, C = nums[0].size() - 1,index = -1;
        
        while(R < rows && C >= 0) {
            if(nums[R][C] == 1) {
                index = R;
                C = C - 1;
            } else {
                R = R + 1;
            }
            
        }
        
        return index;
    }
};


int main() {
    int t;
    cin >> t;

    while (t--) {
        int rows, cols;
        cin >> rows >> cols;

        vector<vector<int>> mat(rows, vector<int>(cols));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat) << endl;
    }

    return 0;
}
