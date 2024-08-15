// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1237/B

#include <bits/stdc++.h>
using namespace std;

// 2 pointers approach to check if end car is not the start car & start car has not been passed earlier

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i=0; i<n; i++) {
        cin >> start[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> end[i];
    }   
    vector<int> passed(n+1, 0);
    int i=0, j=0;
    int cnt = 0;
    while (j<n) {
        passed[end[j]+1]=1;
        if (start[i]==end[j]) {
            i++; j++;
        }
        else {
            if (passed[start[i]+1]==0) {
                cnt++; j++;
            }
            else i++;
        }
    }
    cout << cnt << endl;  
    
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