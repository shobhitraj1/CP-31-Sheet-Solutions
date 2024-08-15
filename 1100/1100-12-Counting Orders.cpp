// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1827/A

#include <bits/stdc++.h>
using namespace std;

/*
Sort both A and B.
The new a_i must satisfies a_i>b_i. But some of the candidates are already chosen as a_j for some j>i. 
However, since a_j>b_j≥b_i, we know that there are exactly (i) candidates already chosen previously by all values of j>i. 
So, there are (number of k such that a_k>b_i) − (i) ways to choose the value of a_i.
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
    vector<int> A(n);
    vector<int> B(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }   
    sort(all(A)); sort(all(B));
    // print(A); print(B);
    int ans = 1;
    int j=0;
    for (int i=0; i<n; i++) {
        if (j<n && A[i]>B[j]) {
            i-=1;
            j+=1;
        }
        else {
            ans = (ans*(j-i))%MOD;
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