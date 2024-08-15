// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1487/B

#include <bits/stdc++.h>
using namespace std;

// If n = even, no problem
// If n = odd, repeats after m steps where m = (n*((n-1)/2))
// pattern is (n-1) steps in first cycle, (n-2) steps in 2nd, 3rd, 4th
// In first cycle, middle one is skipped
// gap = ((n+1)/2)
// In further cycles, 2nd - 1,(1+gap); 2rd - 2,(2+gap)...
/*
In other words, each f=⌊n/2⌋ steps B makes one extra step, so the answer (if both k and spots are 0-indexed) is
(k+(nmod2)⋅⌊k/f⌋)modn
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n&1) {
        int m = n*((n-1)/2); // repeat after m steps
        // cout << "m steps = " << m << endl;
        k = k%m;
        if (k==0) k=m;
        // cout << "k = " << k << endl;
        if (k>n-1) {
            k-=(n-1);
            int cycle = k/(n-2);
            // cout << "k = " << k << ", cycle = " << cycle << endl;
            if (k%(n-2) == 0) {
                int missing1 = cycle, missing2 = cycle+((n+1)/2);
                if (missing2==n) cout << n-1 << endl;
                else cout << n << endl;
                return;
            }
            k-=(n-2)*cycle;
            // cout << "k = " << k << endl;
            int missing1 = cycle+1, missing2 = missing1+((n+1)/2);
            // cout << missing1 << " " << missing2 << endl;
            if (k<missing1) cout << k << endl;
            else if (k>=missing1 && k<missing2-1) cout << k+1 << endl;
            else cout << k+2 << endl;
        }
        else {
            if (k<ceil(n,2)) cout << k << endl;
            else cout << k+1 << endl;
        }
    }
    else {
        int m = k%n;
        if (m==0) m=n;
        cout << m << endl;
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