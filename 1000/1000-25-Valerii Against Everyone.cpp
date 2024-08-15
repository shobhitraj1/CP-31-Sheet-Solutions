// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1438/B

#include <bits/stdc++.h>
using namespace std;

// If any element occurs twice, then YES
// 2^n = 2^n-1 + 2^n-2 + ... + 2^0 + 1
// If b, then 2 times (b-1) or 4 times (b-2) ...
// Some, element has to appear atleast twice for this to fulfill
// For eg. - 5 2 1 [4][3 3] forms such, but if 5 2 1 [3] 4 [3] forms such segments
// So, just check if any element appears atleast twice

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

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

void solve() {
    int n, input;
    cin >> n;
    unordered_map<int, int> myMap;
    bool flag = false;
    for (int i=0; i<n; i++) {
        cin >> input;
        if (myMap.find(input) != myMap.end()) { // exists element
            myMap[input]+=1;
            flag = true;
        }
        else { // new element
            myMap[input] = 1;
        }
    }   
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    
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