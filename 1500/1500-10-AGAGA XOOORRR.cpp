// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1516/B

#include <bits/stdc++.h>
using namespace std;

// If answer exist, it can be brought down to either 2 or 3 equal elements 
// For 2 => can check through prefix and suffix
// For 3 => need 3 subsegements whose xor are equal (as n<=2000, brute force double for loop)

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
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    vector<int> prefix(n), suffix(n);
    prefix[0] = array[0];
    for (int i=1; i<n; i++) {
        prefix[i] = prefix[i-1]^array[i];
    }
    suffix[n-1] = array[n-1];
    for (int i=n-2; i>=0; i--) {
        suffix[i] = suffix[i+1]^array[i];
    }
    // print(prefix);
    // print(suffix);
    for (int i=0; i<n-1; i++) {
        if (prefix[i] == suffix[i+1]) {
            cout << "YES" << endl;
            return;
        }
    }
    for (int i=0; i<n; i++) {
        int prev = prefix[i];
        for (int j=i+1; j<n-1; j++) {
            int cur = prefix[j]^prefix[i];
            int next = suffix[j+1];
            if (prev == cur && cur == next) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;

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