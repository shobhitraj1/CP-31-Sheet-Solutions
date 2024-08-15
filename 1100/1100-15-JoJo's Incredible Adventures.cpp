// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1820/B

#include <bits/stdc++.h>
using namespace std;

// Count max. no of consecutive 1's (take into account cyclic shift) - maybe max comes after shifitng
// If cons=n --> all 1's --> output = n^2
// If cons = even --> output = cons/2 * (cons/2 + 1)
// If cons = odd --> output = ⌈cons/2⌉ * ⌈cons/2⌉

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
    string input;
    cin >> input;
    int n = input.length();
    input+=input;
    int cons = 0; // maximum cyclic consecutive 1's
    int count = 0;
    for (int i=0; i<2*n; i++) {
        if (input[i]=='1') count+=1;
        else {
            if (count>cons) cons = count;
            count = 0;
        }
    }   
    if (count>cons) cons = count;
    
    if (cons>n) { // all 1's
        cout << n*n << endl;
        return;
    }
    if (cons%2==0) {
        int m = cons/2;
        cout << (m)*(m + 1) << endl;
    }
    else {
        int m = ceil(cons,2);
        cout << m*m << endl;
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