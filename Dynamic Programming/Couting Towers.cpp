// Author: Ananyapam7
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
using namespace chrono;
//=============================================CONSTANTS=============================================
const long long MOD  = 1e9 + 7;
const long long MOD1 = 998244353;
const long long inf  = 1e18;
//==============================================MACROS===============================================
#define ll long long
#define ull unsigned long long
#define lld long long double
//==============================================TYPEDEFS==============================================
typedef pair<int, int> pii;
typedef pair<ll, ll>   pl;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef vector<ll>     vl;
typedef vector<pii>    vpii;
typedef vector<pl>     vpl;
typedef vector<vi>     vvi;
typedef vector<vl>     vvl;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//==============================================FUNCTIONS=============================================

#define fo(i,n)        for(ll i = 0; i < n; i++) 
#define fr(i, a, b)    for (ll i = a; i < b; i++)
#define trav(a,v)      for(auto &a:v)
#define pb             push_back
#define mp             make_pair
#define ff             first
#define ss             second
#define clr(x)         memset(x, 0, sizeof(x))
#define all(a)         a.begin(), a.end()
#define sortall(x)     sort(all(x))
#define revsortall(x)  sort(a.begin(), a.end(), greater<int>());
#define nl             cout<<endl

//Vectors
#define count_element(a, x)  ( count(a.begin(), a.end(), x)) // count of an element x in a vector
#define sum(a)               ( accumulate ((a).begin(), (a).end(), 0ll)) //sum of a vector
#define mine(a)              (*min_element((a).begin(), (a).end())) //minimum element
#define maxe(a)              (*max_element((a).begin(), (a).end())) //maximum element
#define max_pos(a)           ((max_element((a).begin(), (a).end())) - a.begin())
#define min_pos(a)           ((min_element((a).begin(), (a).end())) - a.begin())

//Math 
mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count()); // uniform_int_distribution<int>(0, x)(rng)
#define gcd(a, b)       __gcd(a, b)
#define lcm(a, b)       (a * b) / __gcd(a, b)
#define pow2(x)         (1ll<<(x))
ll int_sqrt (ll x) {ll ans = 0;for (ll k = 1LL << 30; k != 0; k /= 2) {if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}
int highestPowerOf2(int n){return (n & (~(n - 1)));}
ll mpow(ll a, ll b, ll MOD) {ll res = 1; while (b > 0){if (b & 1) res = (res * a) % MOD; a = (a * a) % MOD; b >>= 1; } return res; }
ll inv(ll a, ll MOD) {return mpow(a, MOD - 2, MOD);}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
bool isPrime(int n) {if (n == 2 || n == 3 || n == 5) {return true; } if (n % 2 == 0 || n % 3 == 0) {return false; } for (int i=5; i*i<=n; i=i+6) {if (n%i == 0 || n%(i+2) == 0) {return false; } } return true; }
bool issquare(ll n) {if (n >= 0) {ll sr = sqrt(n);return (sr * sr == n);}return false;}
ll factorial(ll n){ll res = 1;for (ll i = 2; i <= n; i++)res = (res * i) % MOD ;return res;}
ll phi(ll n){ll result = n;for(ll p = 2; p * p <= n; ++p){if (n % p == 0){while (n % p == 0)n /= p;result -= result / p;}}if (n > 1)result -= result / n;return result;}
ll findMex(vector<int> arr){int mex = 0; for (auto& i:arr) {if (i == mex) {mex++; } } return mex; }
vi divisors(int n){vi v;for (int i=1; i*i<(n); i++){if (n%i == 0){v.pb(i);if (n/i!=i)v.pb(n/i);}}return v;}
ll count_divisors(ll n){ll count=0;for(int i=1;i*1LL*i<=n;i++){if(n%i==0){count++;if(i!=n/i){count++;}}}return count;}
ll digit_sum(ll n){string s = to_string(n);ll ans=0;for(auto &x:s){ans+=x-'0';}return ans;}
vi prime_factorize(ll n){vi prime_factors;while (n % 2 == 0){prime_factors.push_back(2);n = n/2;}for (int i = 3; i <= sqrt(n); i = i + 2){while (n % i == 0){prime_factors.push_back(i);n = n/i;}}if (n > 2)prime_factors.push_back(n);return prime_factors;}
vi unique_prime_factorize(ll n){vi prime_factors;while (n % 2 == 0){prime_factors.push_back(2);n = n/2;}for (int i = 3; i <= sqrt(n); i = i + 2){while (n % i == 0){prime_factors.push_back(i);n = n/i;}}if (n > 2)prime_factors.push_back(n);prime_factors.erase(std::unique(prime_factors.begin(), prime_factors.end()), prime_factors.end());return prime_factors;}

//Strings
#define toUpperString(s)        transform(s.begin(), s.end(), s.begin(), ::toupper);
#define toLowerString(s)        transform(s.begin(), s.end(), s.begin(), ::tolower);
#define precision(a)            cout << fixed << setprecision(a)
#define sz(x)                   (int)((x).size())

//Standard input
#define si(x)  scanf("%d",&x)
#define sl(x)  scanf("%lld",&x)

//Standard output
#define pi(x)  printf("%d",x)
#define pl(x)  printf("%lld",x)
#define ps(s)  printf("%s",s)

//=============================================TEMPLATES=============================================
template<typename T> // cin >> vector
istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }
template<typename T> // cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; } return ostream; }
//=============================================DEBUGGING=============================================
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '['; __print(x.first); cerr << ','; __print(x.second); cerr << ']';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '['; for (auto &i: x) cerr << (f++ ? " ," : ""), __print(i); cerr << "]";}
void _print() {cerr << "\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define deb(x...) cerr << #x << " = "; _print(x)
#else
#define deb(x...)
#endif

//=============================================MAIN CODE=============================================

ll dp[1000001][2];

// void solve(int tc){
    
// }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cout<<setprecision(12)<<fixed;

    int T = 1;
    auto start1 = high_resolution_clock::now();
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=1;i<1e6;i++){
        dp[i+1][0] += (2*dp[i][0])%MOD;
        dp[i+1][1] += (dp[i][0])%MOD;
        dp[i+1][1] += (4*dp[i][1])%MOD;
        dp[i+1][0] += (dp[i][1])%MOD;

        dp[i+1][0] = (dp[i+1][0])%MOD;
        dp[i+1][1] = (dp[i+1][1])%MOD;
    }
    cin >> T;
    for(int tc=1;tc<=T;tc++) {
      // solve(tc);
        int n;
        cin>>n;
        ll ans = dp[n][1]+dp[n][0];
        cout<<ans%MOD<<endl;
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}