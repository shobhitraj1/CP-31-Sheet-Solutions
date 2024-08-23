// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1883/G1

#include <bits/stdc++.h>
using namespace std;

// Basically, in this version, add m=1 to the array A
// And then we can sort and apply 2 pointers, the removed elements will be the largest of A & smallest of B

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(n);
    A[0] = 1;
    for (int i=1; i<n; i++) {
        cin >> A[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> B[i];
    } 
    sort(all(A));
    sort(all(B));
    int i=0, j=0;
    while (j<n) {
        if (A[i] < B[j]) {
            i++; j++;
        }
        else j++;
    } 
    cout << n-i << endl;
    
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