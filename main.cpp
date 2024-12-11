// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
// 	string myString;
// 	cin >> myString;
// 	cout << myString;

// 	return 0;
// }

// #include <iostream>
// #include <sstream>
// #include <vector>
// using namespace std;

// bool result(const vector<int>& arr, int n) {
// 	long long sum = 0;
// 	for(int num : arr) {
// 		sum += num;
// 	}
	
// 	 if (sum % n != 0) {
//         return false;
//     }



//     return true;
// }

// int main() {
// 	int t;
// 	cin >> t;

// 	while(t--) {
// 		int n;
// 		cin >> n;
// 		vector<int> arr(n);
// 		for(int i = 0; i < n; i++) {
// 			cin >> arr[i];
// 		}

// 		cout << (result(arr, n) ? "YES" : "NO") << endl;

// 	}

// 	return 0;
// }


#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        long long sum = 0;
        int a[n];
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        
        // Check if sum is divisible by n
        if (sum % n == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
