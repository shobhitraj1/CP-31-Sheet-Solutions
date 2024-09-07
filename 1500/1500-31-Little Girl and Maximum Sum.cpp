// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/276/C

#include <bits/stdc++.h>
using namespace std;

// Have to arrange the elements such that sum when picked is maximum
// Precompute the no of times each index is picked using prefix sum range queries
// And then assign greatest element to the index that is picked most time

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
    int n, q;
    cin >> n >> q;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    sort(all(array), greater<>());
    int l, r; 
    vector<int> pref(n+1, 0);
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        l--; r--;
        pref[l] += 1;
        pref[r+1] -= 1;
    }
    for (int i=1; i<=n; i++) {
        pref[i] += pref[i-1];
    }
    sort(pref.begin(), pref.begin()+n, greater<>());
    // print(pref);
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += (pref[i]*array[i]);
    }
    cout << sum << endl;
    
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}