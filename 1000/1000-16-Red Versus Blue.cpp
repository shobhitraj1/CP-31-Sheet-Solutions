// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1659/A

#include <bits/stdc++.h>
using namespace std;

// distributing r in (b+1) slots such that max r in any slot is minimised

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
    int n, r, b;
    cin >> n >> r >> b;
    int max = ceil(r,b+1); // max R's on each slot (b+1-left slots)
    int left = ((max)*(b+1)) - r; // subtract 1 from each left slots
    string res2 = "";
    for (int i=0; i<max-1; i++) {
        res2+="R";
    }
    res2+="B";
    string res1 = "R" + res2;
    string result = "";
    for (int i=0; i<b+1-left; i++) {
        result += res1;
    }
    for (int i=0; i<left; i++) {
        result += res2;
    }
    result.erase(n,1); // remove the last B
    cout << result << endl;        
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}