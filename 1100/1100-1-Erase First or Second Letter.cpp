// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1917/B

#include <bits/stdc++.h>
using namespace std;

/*
Can make strings of size n, n-1, n-2 ... 1
n length = 1 (no. of distinct character in first place)
n-1 length = no. of distinct character in first 2 places
n-2 length = no. of distinct character in first 3 places
... and so on
because can delete these distinct characters to make unique
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

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
    string input;
    cin >> input;
    set<char> st;
    int ans = 0;
    for (int i=0; i<n; i++) {
        st.insert(input[i]);
        ans += st.size();
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