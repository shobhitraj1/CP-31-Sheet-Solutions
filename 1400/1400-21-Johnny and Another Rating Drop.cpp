// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1362/C

#include <bits/stdc++.h>
using namespace std;

/*
check the pattern of Binary representation of the numbers below :-
Decimal	E	D	C	B	A
0	    0	0	0	0	0
1	    0	0	0	0	1
2	    0	0	0	1	0
3	    0	0	0	1	1
4	    0	0	1	0	0
5	    0	0	1	0	1
6	    0	0	1	1	0
7	    0	0	1	1	1
8	    0	1	0	0	0
9	    0	1	0	0	1
10	    0	1	0	1	0
11	    0	1	0	1	1
12	    0	1	1	0	0
13	    0	1	1	0	1
14	    0	1	1	1	0
15	    0	1	1	1	1
16	    1	0	0	0	0

Notice that,
Every alternate bits in A are set
Every 2 alternate bits in B are set
Evert 4 alternate bits in C are set
........
This will keep on repeating for every power of 2.
So, switches are made :-
after every alternate bit in A
after every 2 alternate bits in B
after every 4 alternate bits in C
........
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
    int n;
    cin >> n;
    int bits = (int) (log2(n)+1);
    int switches = 0;
    for (int i=0; i<bits; i++) {
        int cur = (1LL<<i);
        switches += (n/cur);
    }
    cout << switches << endl;
    
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