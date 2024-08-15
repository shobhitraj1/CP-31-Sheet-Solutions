// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1831/B

#include <bits/stdc++.h>
using namespace std;

// Have to find the greatest sequence of same consecutive nos. when merging
// i.e. max(maxConsofanElement(A) + maxConsofanElement(B))

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
    vector<int> A(n);
    vector<int> B(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }   
    int Acons[2*n+1] = {0};
    Acons[A[0]] = 1;
    int count = 1;
    for (int i=1; i<n; i++) {
        if (A[i]==A[i-1]) count+=1;
        else {
            if (count>Acons[A[i-1]]) Acons[A[i-1]] = count;
            count = 1;
        }
    }
    if (count>Acons[A[n-1]]) Acons[A[n-1]] = count;

    int Bcons[2*n+1] = {0};
    Bcons[B[0]] = 1;
    count = 1;
    for (int i=1; i<n; i++) {
        if (B[i]==B[i-1]) count+=1;
        else {
            if (count>Bcons[B[i-1]]) Bcons[B[i-1]] = count;
            count = 1;
        }
    }
    if (count>Bcons[B[n-1]]) Bcons[B[n-1]] = count;
    int max = 0;

    // for (int i=0; i<2*n+1; i++) {
    //     cout << Acons[i] << " ";
    // }
    // cout << endl;
    // for (int i=0; i<2*n+1; i++) {
    //     cout << Bcons[i] << " ";
    // }
    // cout << endl;

    for (int i=0; i<2*n+1; i++) {
        if (Acons[i]+Bcons[i]>max) max = Acons[i]+Bcons[i];
    }
    cout << max << endl;

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