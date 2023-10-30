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

//Graphs
ll dx[4] = {1,-1,0,0};
ll dy[4] = {0,0,1,-1};
// vector<pair<ll, ll>> movements = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
// bool isvalid(ll i, ll j, ll n, ll m){return i>=0 && j>=0 && i<n && j<m;}

//Strings
// vector<char> letter =           {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
// 0, 4, 8, 14, 20 (positions of vowels)
// vector<char> vowel  =           {'a', 'e', 'i', 'o', 'u'};

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

void solve(int tc){
    int n, m;cin>>n>>m;
    vi v(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    
    int ans=0;
    int dp[n+5][m+5];

    memset(dp, 0, sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int x=1;x<=m;x++){
            if(i==1){
                if(v[i]==0 || v[i]==x){
                    dp[i][x] = 1;
                }
                else{
                    dp[i][x]=0;
                }
            }
            else{
                if(v[i]==0 || v[i]==x){
                    dp[i][x] = ((dp[i-1][x]+dp[i-1][x-1])%MOD+dp[i-1][x+1])%MOD;
                }
                else{
                    dp[i][x]=0;
                }
            }
        }
    }

    for(int x=1;x<=m;x++){
        ans = (ans + dp[n][x])%MOD;
    }

    cout<<ans<<endl;

}

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
    // cin >> T;
    for(int tc=1;tc<=T;tc++) {
      solve(tc);
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}

//===============================================NOTES===============================================

// Converts to lower case
// transform(s.begin(), s.end(), s.begin(), [] (char c) {
//     return tolower(c);
// });

// This will erase all duplicates from the string and keep only unique characters
// s.erase(unique(s.begin(), s.end()), s.end());

// Bit manipulations
// int x = 5328; // 00000000000000000001010011010000
// __builtin_clz(x) << "\n"; // Leading zeroes: 19
// __builtin_ctz(x) << "\n"; // Tail zeroes: 4
// __builtin_popcount(x) << "\n"; // 5
// __builtin_popcountll(x) // if x is a long long
// __builtin_parity(x) << "\n"; // If number of ones are Odd -> 1, Even ->0
// __lg(x); //Index of the highest set bit from the right, 0 based indexed
// 2-based logarithm of integer number

// Print a number in binary
// cout<<std::bitset<8>(x)<<endl;
// ~x -> toggle bits of x
// 1<<n = 2^n

// Bitsets
// bitset<10> s;
// s[1] = 1;
// s[3] = 1;
// s[4] = 1;
// s[7] = 1;
// s.count();

// bitset<10> a, b;
// bitset<10> c = a&b;
// bitset<10> d = a|b;
// bitset<10> e = a^b;

// Vectors
// vector<tuple<int,int,int>> v;
// v.push_back({2,1,4});
// v.push_back({1,5,3});
// v.push_back({2,1,3});
// sort(v.begin(), v.end());
// // result: [(1,5,3),(2,1,3),(2,1,4)]

// bool comp(string a, string b) {
//     if (a.size() == b.size()) return a < b;
//     else return a.size() < b.size();
// }

// sort(v.begin(), v.end(), comp);

// reverse(v.begin(),v.end()); 
// sort(v.rbegin(), v.rend());

// lower_bound gives an iterator to the 
// first element in a sorted range whose value is at least x, and 
// upper_bound gives an iterator to the first element whose value is larger than x

// vector<int> v = {2,3,3,5,7,8,8,8};
// auto a = lower_bound(v.begin(),v.end(),5);
// auto b = upper_bound(v.begin(),v.end(),5);
// cout << *a << " " << *b << "\n"; // 5 7

// Note that the above functions only work correctly when the given range is sorted.
// The functions use binary search and find the requested element in logarithmic time.

// the following code creates a vector that contains the
// unique elements of the original vector in a sorted order:
// sort(all(v));
// v.erase(unique(v.begin(),v.end()),v.end());

// 2D vectors:
// vector<vector<int>> v(n , vector<int> (m, 0));

// Sets
// An important property of sets is that all their elements are distinct. Thus, the
// function count always returns either 0 (the element is not in the set) or 1 (the
// element is in the set), and the function insert never adds an element to the set if
// it is already there.

// auto it = s.find(x);
// if (it == s.end()) {
//    // x is not found
// }

// auto first = s.begin();
// auto last = s.end(); last--;
// cout << *first << " " << *last << "\n";

// cout << *s.lower_bound(x) << "\n";
// cout << *s.upper_bound(x) << "\n";

// Mulitsets
// multiset<int> s;
// s.insert(5);
// s.insert(5);
// s.insert(5);
// cout << s.count(5) << "\n"; // 3

// The function erase removes all copies of a value from a multiset:
// s.erase(5);
// cout << s.count(5) << "\n"; // 0

// Often, only one value should be removed, which can be done as follows:
// s.erase(s.find(5));
// cout << s.count(5) << "\n"; // 2

// Maps
// The function count checks if a key exists in a map:
// if (m.count("aybabtu")) {
// // key exists
// }

// Priority Queue
// While a multiset provides all the operations of a priority queue and more,
// the benefit of using a priority queue is that it has smaller constant factors.
// By default, the elements in a C++ priority queue are sorted in decreasing order
// priority_queue<int> q;
// q.push(3);
// q.push(5);
// q.push(7);
// q.push(2);
// cout << q.top() << "\n"; // 7
// q.pop();
// cout << q.top() << "\n"; // 5
// q.pop();
// q.push(6);
// cout << q.top() << "\n"; // 6
// q.pop();

// If we want to create a priority queue that supports finding and removing the
// smallest element, we can do it as follows:
// priority_queue<int,vector<int>,greater<int>> q;

//     indexed_set s;
//     s.insert(2);
//     s.insert(3);
//     s.insert(7);
//     s.insert(9);
// //  The speciality of this set is that we have access to the indices that the elements
// //  would have in a sorted array.(decreasing)
//     auto x = s.find_by_order(2);
//     cout << *x << "\n"; // 7
//     cout << s.order_of_key(7) << "\n"; // 2
// //  If the element does not appear in the set, we get the position that the element
// //  would have in the set:
//     cout << s.order_of_key(6) << "\n"; // 2
//     cout << s.order_of_key(8) << "\n"; // 3
//     cout << s.size();

// If the amount of data is unknown, the following loop is useful:
// while (cin >> x) {
//     // code
// }

// All global arrays are initialized to 0;
// Maximum size of global arrays is 10^7, and local arrays is 10^5

// if(a&1) works for negative numbers as well

// for(int i=0;i<q;i++)    cout<<string(p+1,'R')<<'B'; //will directly cout a string instead of printing letter by letter,

// is_sorted(s.begin(), s.end()) checks if a string is sorted

// substr(position, length)

// vector<int> v = {1,5,6,80,9,5,6};
// vector<int> prefix(v.size());
// vector<int> suffix(v.size());
// partial_sum(v.begin(),v.end(),prefix.begin());
// partial_sum(v.rbegin(),v.rend(),suffix.rbegin());

// Uniform Random Sampling
// default_random_engine generator;
// uniform_int_distribution<int> dist(1, n);
// int number = dist(generator);