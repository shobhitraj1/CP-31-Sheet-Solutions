// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1878/E

#include <bits/stdc++.h>
using namespace std;

// As property of AND such that resultant AND is always <= a_i (So not possible when k > l, else always r=l possible)
// Also, using property of AND, even if one 0 bit encountered, resultant bit of AND will always be 0 further from that point 
// Predicate function --> TTTTFFFF (Binary Search with maintaining the last 0 bit observed)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

bool isSufficientAND (vector<vector<int>>& last0, int first, int last, int k) {
    int num = 0;
    // cout << first << " " << last << endl;
    for (int j=0; j<31; j++) {
        if (last0[last][j] < first) {
            num |= (1<<j);
        }
    }
    // cout << num << " " << k << endl;
    return num >= k;
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n+1);
    vector<vector<int>> last0(n+1, vector<int>(31, 0));
    for (int i=1; i<=n; i++) {
        cin >> array[i];
        for (int j=0; j<31; j++) {
            if (array[i] & (1<<j)) last0[i][j] = last0[i-1][j];
            else last0[i][j] = i;
        }
    }   
    // for (int i=0; i<=n; i++) {
    //     for (int j=0; j<4; j++) {
    //         cout << last0[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int q, l, k; 
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> l >> k;
        if (array[l]<k) cout << -1 << " ";
        else {
            // output the maximum r
            // TTTTTFFFFF --> need rightmost T
            int low = l;
            int high = n;
            while (high-low>1) {
                int mid = (low+high)/2;
                if (isSufficientAND(last0, l, mid, k)) low = mid;
                else high = mid-1;
            }
            if (isSufficientAND(last0, l, high, k)) cout << high << " ";
            else if (isSufficientAND(last0, l, low, k)) cout << low << " ";
            else cout << l << " "; // will never reach 
        }
    }
    cout << endl;    
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