// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;

        while(row < rows && col >= 0) {
            if(matrix[row][col] == target) return true;
            else if(target > matrix[row][col]) row++;
            else col--;
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
