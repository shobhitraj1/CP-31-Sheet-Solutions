// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1692/G

#include <bits/stdc++.h>
using namespace std;

// convert into success array & check k consecutive 1's appears how many times

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }  
    vector<int> success(n, 0);
    for (int i=1; i<n; i++) {
        if (array[i]*2 > array[i-1]) success[i]=1;
    } 
    // print(success);
    int ans = 0, count = 0;
    for (int i=0; i<n; i++) {
        if (success[i]==1) {
            count += 1;
            if (count >= k) ans += 1;
        }
        else count = 0;
    }
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