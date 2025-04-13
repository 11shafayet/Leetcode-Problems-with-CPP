// https://www.geeksforgeeks.org/rat-in-a-maze/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>> &board, int r, int c) {
        int n = board.size();
        
        if(r < 0 || r >= n || c < 0 || c >= n || board[r][c] == 0 || board[r][c] == -1) return false;
        
        return true;
    }
    
    void helper(vector<vector<int>> &board, vector<string> &ans, string path, int r, int c) {
        int n = board.size();
        // base case
        if(r == n - 1 && c == n - 1) {
            ans.push_back(path);
            return;
        }
        if(!isValid(board, r, c)) return;
        
        int temp = board[r][c];
        board[r][c] = -1;
        
        helper(board, ans, path+"U", r - 1, c); // up
        helper(board, ans, path+"D", r + 1, c); // down
        helper(board, ans, path+"R", r, c + 1); // right
        helper(board, ans, path+"L", r, c - 1); // left
        
        board[r][c] = temp;
    }
    
    vector<string> maze(vector<vector<int>> &board) {
        vector<string> ans;
        int n = board.size();
        string path = "";
        
        if(board[0][0] == 0 || board[n - 1][n - 1] == 0) return ans;
        
        helper(board, ans, path, 0, 0);
        
        return ans;
    }
};

int main() {
    vector<vector<int>> board = { {1, 0, 0, 0}, 
                                  {1, 1, 0, 1}, 
                                  {0, 1, 0, 0}, 
                                  {1, 1, 1, 1} };
    
    Solution ss;
    
    vector<string> results = ss.maze(board);
    
    for(auto item : results) {
        cout << item << ", ";
    }
    
    return 0;
}