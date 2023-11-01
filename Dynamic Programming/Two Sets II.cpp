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
    cin>>n;
    int dp[n+1][(n*n)/2 + 5];
    dp[0][0] = 1;
    for(int i=1;i<(n*n)/2;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int x=0;x<=n*(n+1)/4;x++){
            dp[i][x] = (( (x<i) ? 0 : dp[i-1][x-i]) + dp[i-1][x])%MOD;
        }
    }
    if(n*(n+1) % 4 != 0)cout<<0<<endl;
    else cout<<((dp[n][n*(n+1)/4])*500000004)%MOD;

}