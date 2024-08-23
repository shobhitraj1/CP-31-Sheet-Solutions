// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1374/D

#include <bits/stdc++.h>
using namespace std;

// Keep track how much each element has to be increased to make it divisible by k (as operation only once)
// Track which x is required most - let it be maxi times
// therefore, maxi-1 times cycle of k increments on x will be made and then increment upto that x with maxi

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename K, typename V>
void print(const map<K, V> &m) {
    for (const auto &el : m) {
        cout << "{" << el.first << ": " << el.second << "} " << endl;
    }
}

void solve() {
    int n, k, input;
    cin >> n >> k;
    map <int, int> mp;
    int maxi = 0, elem = -1;
    for (int i=0; i<n; i++) {
        cin >> input;
        int rem = (k - (input%k));
        if (rem!=k) {
            mp[rem]++; 
            if (maxi<=mp[rem]) {
                if (maxi==mp[rem]) elem = max(elem, rem);
                else elem = rem;
                maxi = mp[rem];
            }
        }
    }    
    // print(mp);
    int ans = max((maxi-1)*k,0LL) + (elem+1);
    cout << ans << endl; 
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}