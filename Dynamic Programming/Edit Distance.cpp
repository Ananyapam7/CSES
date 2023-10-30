#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int solve(string word1, string word2, int n, int m, vector<vector<int>> &dp){
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(n==0)
            return m;
        if(m==0)
            return n;
        if(word1[n-1]==word2[m-1])
            return dp[n][m] = solve(word1, word2, n-1, m-1, dp);
        else
            return dp[n][m] = 1+min({solve(word1, word2, n, m-1, dp), solve(word1, word2, n-1, m, dp), solve(word1, word2, n-1, m-1, dp)});
}

int32_t main() {
    string word1, word2;
    cin>>word1>>word2;
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout<<solve(word1, word2, n, m, dp);
}
// Giving TLE 

// AC code
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'

// int editDistance(string word1, string word2) {
//     int n = word1.size();
//     int m = word2.size();

//     // Create a DP table of size (n+1) x (m+1)
//     vector<vector<int>> dp(n+1, vector<int>(m+1));

//     // Initialization
//     for(int i = 0; i <= n; i++) {
//         dp[i][0] = i;
//     }
//     for(int j = 0; j <= m; j++) {
//         dp[0][j] = j;
//     }

//     // Fill the DP table
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             if(word1[i-1] == word2[j-1]) {
//                 dp[i][j] = dp[i-1][j-1];
//             } else {
//                 dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
//             }
//         }
//     }

//     return dp[n][m];
// }

// int32_t main() {
//     string word1, word2;
//     cin >> word1 >> word2;
//     cout << editDistance(word1, word2) << endl;
// }
