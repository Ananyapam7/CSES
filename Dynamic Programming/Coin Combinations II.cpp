#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main(){
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  
  long long int n,x,t;
  cin>>n>>x;
  
  set<long long int> coins;
  
  for(long long int i=0;i<n;i++){
    cin>>t;
    coins.insert(t);
  }
  
  vector<long long int> dp(x+1,0);
  dp[0]=1;
  for(auto &c: coins){
    for(long long int i=1;i<=x;i++){
      if(i-c >= 0)
        dp[i] += dp[i-c]%mod;
      dp[i] = dp[i]%mod;
    }
  }
  
  cout <<dp[x]<< endl;
  return 0;
  
}