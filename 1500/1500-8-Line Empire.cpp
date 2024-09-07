// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1659/C

#include <bits/stdc++.h>
using namespace std;

// Check for each conquered kingdom if making it the capital or continuing with the current capital is more beneficial
// Don't need to check the kingdoms between current capital and current conquered kingdom because already checked for them when conquered them
// To make checking efficient, compute suffix sum
// And as the kingdoms are in increasing order => suffix[i+1] - (left * array[current]) will always be greater than zero

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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> array(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> array[i];
    }   
    vector<int> suffix(n+1, 0);
    suffix[n] = array[n];
    for (int i=n-1; i>=0; i--) {
        suffix[i] = suffix[i+1] + array[i];
    }
    int ans = 0, curIdx = 0;
    for (int i=1; i<=n; i++) {
        // conquer kingdom
        ans += (b*(array[i]-array[curIdx]));
        // check if should make currently conquered kingdom capital or not
        if (i<n) {
            if ((suffix[i+1]-(n-i)*array[curIdx])*b > a*(array[i]-array[curIdx]) + (suffix[i+1]-(n-i)*array[i])*b) {
                ans += (a*(array[i]-array[curIdx]));
                curIdx = i;
            }
        }
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