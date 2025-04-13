
// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
      // find the maximum value from the array
      int maxValue = *max_element(arr.begin(), arr.end());
      
      // create an array with the length of maxValue + 1 and initialize all the value to 0
      vector<int> myArray(maxValue + 1, 0);
      
      // traverse the main arr and increase the number by 1 in myArray
      for(auto num : arr) {
          myArray[num]++;
      }
      
      //  find the kth element as the list is sorted
      int count = 0;
      for(int i = 0; i <= maxValue; i++) {
          count += myArray[i];
          if(count >= k) {
              return i;
          }
      }
      
      return -1;
    }
};


int main() {
    int test_case;
    cin >> test_case;  
    cin.ignore();  
    while (test_case--) {
        int k;
        vector<int> arr;
        string input;
        
        // Read the array of numbers (space-separated)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        
        // Read the value of k
        getline(cin, input);
        stringstream ss2(input);
        ss2 >> k;
        
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

