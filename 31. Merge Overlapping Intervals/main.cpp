//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
      int n = arr.size();

      sort(arr.begin(), arr.end());
      vector<vector<int>> res;

      res.push_back(arr[0]);
      
      for (int i = 0; i < n; i++) {
          vector<int>& lastItem = res.back();
          vector<int>& currItem = arr[i];
          
          if(currItem[0] <= lastItem[1]) {
              lastItem[1] = max(currItem[1], lastItem[1]);
          } else res.push_back(currItem);
         
      }
      return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends