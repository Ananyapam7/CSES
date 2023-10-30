#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const long long MOD  = 1e9 + 7;

int dp[1000001];

int32_t main() {
  int n;cin>>n;
  // dp[i] <- Number of ways to get a sum of i by throwing a dice having numbers 1,2,3,4,5,6
  // dp[x] = dp[x-1] + ... dp[x-6]
  dp[0] = 1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=6;j++){
      if(i>=j){
        dp[i] +=(dp[i-j])%MOD;
      }
      dp[i]%=MOD;
    }
  }
  cout<<dp[n]<<endl;
}