// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1567/B

#include <bits/stdc++.h>
using namespace std;

// For MEX, all elements from 0 to mex-1 must be there in the array
// XOR of all elements from 0 to mex-1 :-
// Pattern :- XOR till 
// 4k = 0 (i.e. 0^1^2^...^4k-1)
// 4k+1 = 4k (i.e 0^1^2^...^4k)
// 4k+2 = 1 (i.e 0^1^2^...^4k+1)
// 4k+3 = 4k+3 (i.e 0^1^2^...^4k+2)
// And if their resultant xor is XOR, then good enough or else one more element
// And that element would be (resultant xor)^XOR due to cyclic property of bitwise xor

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
    int a, b;
    cin >> a >> b;
    int ans = 0;
    // for (int i=0; i<a; i++) {
    //     ans = ans^i;
    // }
    if (a%4==0) ans = 0;
    else if (a%4==1) ans = a-1;
    else if (a%4==2) ans = 1;
    else ans = a;

    if (ans == b) cout << a << endl;
    else {
        if ((ans^b) != a) cout << a+1 << endl;
        else cout << a+2 << endl;
    }

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