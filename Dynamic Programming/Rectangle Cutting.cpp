#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const double PI = acos(-1.0);

const int N = 501;
int dp[N][N]; // dp[i][j] -> min no of cuts req to break i * j into

int go(int n, int m) {
    if (n == m) return 0;
    if (n == 1) return m - 1;
    if (m == 1) return n - 1;

    if (dp[n][m] != -1) return dp[n][m];
    if (dp[m][n] != -1) return dp[m][n]; // Simple but essential optimization

    dp[n][m] = 1e9;

    for (int x = 1; x < n - 1; x++) {
        dp[n][m] = min(dp[n][m], go(x, m) + go(n - x, m) + 1);
    }

    for (int y = 1; y < m - 1; y++) {
        dp[n][m] = min(dp[n][m], go(n, y) + go(n, m - y) + 1);
    }

    return dp[n][m];
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    memset(dp, -1, sizeof dp);

    cout << go(n, m) << endl;
}