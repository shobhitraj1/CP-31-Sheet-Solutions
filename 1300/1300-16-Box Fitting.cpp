// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1498/B

#include <bits/stdc++.h>
using namespace std;

// just fit the largest boxes first in the residue or create new level

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort(all(array));
    priority_queue<int> pq;
    for (int i=n-1; i>=0; i--) {
        if(!pq.empty() && pq.top()>=array[i]) {
            int elem = pq.top(); pq.pop();
            pq.push(elem-array[i]);
        }
        else {
            pq.push(w-array[i]);
        }
    }
    cout << pq.size() << endl;
    
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