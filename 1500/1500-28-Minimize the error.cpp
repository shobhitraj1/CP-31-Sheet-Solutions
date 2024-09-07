// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/960/B

#include <bits/stdc++.h>
using namespace std;

// As square is increasing func, as abs diff increases, it increases, 
// So, instead of greedly making the largest square 0, we should decrease the abs diff using the operations
// This will help the overall sum of the square error
// Also, after error becomes 0, if operations are left :-
// If even, each a_i & b_i can be increased and error will still be 0
// If odd, one a_i in the end has to increased and error will be 1

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> A(n), B(n);
    priority_queue<int> pq;
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> B[i];
        if (A[i]==B[i]) continue;
        pq.push(abs(A[i]-B[i]));        
    }   
    int ops = k1+k2;
    while (ops) {
        if (pq.empty()) break;
        else {
            int largest = pq.top();
            pq.pop();
            largest--;
            if (largest) pq.push(largest);
            ops--;
        }
    }
    int sum = 0;
    while (!pq.empty()) {
        int elem = pq.top();
        pq.pop();
        sum += (elem*elem);
    }
    if (ops>0 && ops&1) sum = 1;
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}