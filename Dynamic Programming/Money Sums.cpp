#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    int n;
    cin>>n;
    bitset<100001> temp;
    temp[0]=1;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        temp |= temp<<x;
    }
    vector<int> ans;
    for(int i=0; i<=100001; i++){
        if(temp[i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v<<" ";
    }
}