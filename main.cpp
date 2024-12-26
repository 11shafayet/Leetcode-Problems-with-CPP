#include <iostream>
#include <vector>
#include <set>
using namespace std;

int minOperations(vector<int> &arr) {
    set<int> unique;
    for (int num : arr) {
        unique.insert(num);
    }
    
    if (unique.count(0)) {
        return 1; // At least one zero exists, so one operation suffices.
    }
    
    // Check if the MEX of the entire array is 0
    int mex = 0;
    for (int num : unique) {
        if (num != mex) {
            break;
        }
        mex++;
    }
    
    if (mex == 0) {
        return 1; // The array's MEX is 0, so one operation suffices.
    } else {
        return 2; // No zeros and MEX is not 0, so two operations are needed.
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << minOperations(arr) << endl;
    }
    return 0;
}
