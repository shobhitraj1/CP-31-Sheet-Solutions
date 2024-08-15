// Created by Shobhit Raj
// https://codeforces.com/problemset/problem/1914/D

#include <bits/stdc++.h>
using namespace std;

// Try for 3 maximum (for each) combinations for all 3 activities

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
    vector<pair<int, int>> A, B, C, D, E, F;
    for (int i=0; i<n; i++) {
        cin >> input;
        A.emplace_back(input, i);
    }   
    for (int i=0; i<n; i++) {
        cin >> input;
        B.emplace_back(input, i);
    }   
    for (int i=0; i<n; i++) {
        cin >> input;
        C.emplace_back(input, i);
    }   
    sort(all(A)); sort(all(B)); sort(all(C));
    for (int i=n-1; i>=0; i--) {
        D.emplace_back(A[i]);
        E.emplace_back(B[i]);
        F.emplace_back(C[i]);
    }
    int sum = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (D[i].second != E[j].second && D[i].second != F[k].second && E[j].second != F[k].second) {
                    sum = max(sum, D[i].first+E[j].first+F[k].first);
                }
            }
        }
    }
    cout << sum << endl;


    
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