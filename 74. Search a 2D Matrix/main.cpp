// https://leetcode.com/problems/search-a-2d-matrix/description/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    //////////////// BRUTE FORCE APPROACH ////////////////
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     for(auto mat : matrix) {
    //         for(int num : mat) {
    //             if(num == target) return true;
    //         }
    //     }

    //     return false;
    // }


    //////////////// BINARY SEARCH APPROACH ////////////////
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows * cols - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / cols, col = mid % cols;
            if(matrix[row][col] == target) return true;
            else if(target < matrix[row][col]) high = mid - 1;
            else low = mid + 1;
        }
        
        return false;
    }
};


int main() {
    int t;
    cin >> t;

    while (t--) {
        int rows, cols, target;
        cin >> rows >> cols >> target;

        vector<vector<int>> mat(rows, vector<int>(cols));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        bool found = obj.searchMatrix(mat, target);
        cout << (found ? "true" : "false") << endl;
    }

    return 0;
}
