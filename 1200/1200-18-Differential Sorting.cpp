// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1635/C

#include <bits/stdc++.h>
using namespace std;

/*
First of all, if a_n−1>a_n, then the answer is −1 since we can't change the last two elements.
If a_n≥0, there exists a simple solution: perform the operation (i,n−1,n) for each 1≤i≤n−2.
Otherwise, the answer exists if and only if the initial array is sorted.
As if a_n<0, in the last, a_n-1 - a_n will be greater than a_n-1 & a_n-2>a_n-1 (not sorted)
*/

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
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    if (array[n-1]<array[n-2]) {
        cout << -1 << endl;
        return;
    }
    if (array[n-1] < 0) {
        for (int i=0; i<n-1; i++) {
            if (array[i]>array[i+1])  {
                cout << -1 << endl;
                return;
            }
        }
        cout << 0 << endl;
        return;
    }
    cout << n-2 << endl;
    for (int i=0; i<n-2; i++) {
        cout << i+1 << " " << n-1 << " " << n << endl;
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