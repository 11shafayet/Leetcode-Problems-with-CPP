// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& boards, int n, int k, int maxSum) {
        int worker = 1, board = 0;

        for(int num : boards) {
            if(num > maxSum) return false;

            if(board + num > maxSum){
                worker++;
                board = num;
            } else
                board += num;
        }

        return worker <= k;
    }

    int findLargestMinDistance(vector<int> &boards, int k){
        int n = boards.size();

        int low = 0, high = 0, ans = -1;

        for(int num : boards) {
            high += num;
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isValid(boards, n, k, mid)) {
                // go left. Search of smaller answer
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
        cout << ob.findLargestMinDistance(nums, m) << endl;

        cout << "~" << endl;
    }
    return 0;
}