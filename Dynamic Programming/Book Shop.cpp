#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> price(n), pages(n);
  for (int&v : price) cin >> v;
  for (int&v : pages) cin >> v;
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      //dp[i][j] = dp[i-1][j];
      if (j-price[i-1] >= 0) {
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i-1]]+pages[i-1]);
      }
      else if(j-price[i-1] < 0){
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout << dp[n][x] << endl;
}