// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1215/B

#include <bits/stdc++.h>
using namespace std;

// When adding i-th element to the array (i more subsegments are possible --> (i-1) combined with last index + 1 itself)
// If element being added is positive, simply last (i-1)th is carried forward & 1 added to positive for itself
// Else, last (i-1)th is swapped as positive X negative will make negative & negative X negative will make positive + 1 added to negative for itself
// Map can be used to track -ve & +ve product, we have used 2 variables

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, input;
    cin >> n;
    int pos = 0, neg = 0;
    int pos_ans = 0, neg_ans = 0;
    for (int i=0; i<n; i++) {
        cin >> input;
        if (input>0) {
            pos_ans += (pos+1);
            neg_ans += neg;
            pos++;
        }
        else {
            pos_ans += (neg);
            neg_ans += (pos+1);
            pos++;
            swap(pos, neg);
        }
    }   
    cout << neg_ans << " " << pos_ans << endl;   
    
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