// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1110/B

#include <bits/stdc++.h>
using namespace std;

// if k=n, all breaks can be repaired with 1cm tape, but as atmost k allowed
// repair the smallest gap distances with the tape & the longer gaps with 1cm tape over the 2 ends
// Go the opposite way, start with k=1, and then start removing the tape between the longer gaps 

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> array(n);
    vector<int> tapes;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (i>0) tapes.pb(array[i]-array[i-1]-1); // -1 for in between distance
    }  
    int total = array[n-1]-array[0]+1;
    sort(all(tapes), greater<>());
    for (int i=0; i<k-1; i++) { // k-1 divides for k tapes
        total -= tapes[i];
    }
    cout << total << endl;
   
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