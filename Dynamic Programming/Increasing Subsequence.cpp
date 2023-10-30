#include <bits/stdc++.h>
using namespace std;

// Patience Sorting Algorithm
int length_of_LIS(vector<int>& nums) {
    vector<int> lis;

    for (int num : nums) {
        // Using lower_bound to find the position in 'lis' where 'num' should be inserted (replaced with!) to keep 'lis' sorted.
        auto it = lower_bound(lis.begin(), lis.end(), num);

        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }

    return lis.size();
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << length_of_LIS(arr) << endl;

    return 0;
}