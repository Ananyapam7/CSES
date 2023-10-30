// Author: Ananyapam7
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define pb push_back
#define mp make_pair
const int mod = 1000000007;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  
  int n;
  cin>>n;
  vector<int> dp(n+1,1e9);
  dp[0]=0;
  
  for(int i=1;i<=n;i++){
    for (char c : to_string(i)) {
      dp[i] = min(dp[i], dp[i-(c-'0')]+1);
    }
  }
  
  cout<<dp[n]<<endl;
  return 0;
}