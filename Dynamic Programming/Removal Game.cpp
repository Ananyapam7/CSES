#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int MOD = 1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

      int n;
      cin >> n;
      vector<int> x(n);
      long long sum = 0;
      for (int&v : x) {
        cin >> v;
        sum += v;
      }

      vector<vector<long long>> dp(n,vector<long long>(n));
      for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
          if (l == r) {
        dp[l][r] = x[l];
          } else {
        dp[l][r] = max(x[l]-dp[l+1][r],
                   x[r]-dp[l][r-1]);
          }
        }
      }
      cout << (sum+dp[0][n-1])/2 << endl;

}