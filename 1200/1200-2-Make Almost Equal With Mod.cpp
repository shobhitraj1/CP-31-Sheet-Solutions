// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1909/B

#include <bits/stdc++.h>
using namespace std;

// k=2 works unless either all the numbers are even or all the numbers are odd
// a_i mod 2^j corresponds to the last j digits in the binary representation of ai. 
// There must exist j such that the last j digits make exactly 2 distinct blocks.
// Remainder will be the 2 distinct blocks [there always be as all a_i are distinct]
// a_i<=10^17 suggests that 64-bits in binary representations
// Alternate --> check from all 2^m (m = 1 to 57) such that distinct 2 remainders

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
    vector<int> array(n);
    int cntEven = 0, cntOdd = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (array[i]&1) cntOdd+=1;
        else cntEven+=1;
    }   
    if (cntEven && cntOdd) cout << 2 << endl;
    else {
        for (int i=0; i<64; i++) {
            int setbit = 0;
            for (int j=0; j<n; j++) {
                if (array[j]&(1LL<<i)) setbit+=1; // use 1LL or else shift too large
            }
            if (setbit==n || setbit==0) continue;
            else {
                cout << (1LL<<(i+1)) << endl; // use 1LL or else shift too large
                break;
            }
        }
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

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}