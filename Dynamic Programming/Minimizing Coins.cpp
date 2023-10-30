#include <bits/stdc++.h>
using namespace std;

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
  
  for(long long int i=1;i<=x;i++){
    dp[i]=INT_MAX;
    for(auto &c: coins){
      if(i-c >= 0)
        dp[i] = min(dp[i],dp[i-c]+1);
    }
  }
  
  cout << (dp[x] >= INT_MAX ? -1 : dp[x]) << endl;
  return 0;
  
}
