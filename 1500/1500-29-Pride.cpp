// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/891/A

#include <bits/stdc++.h>
using namespace std;

// If hcf of array != 1, then can't be converted => output -1
// If any element(s) 1, then rest elements can be converted to 1 easily taking hcf => n - cnt1
// If hcf = 1 but no 1's present, then fincd the shortest distance pair such that their hcf = 1, then convert rest to 1
// As n<2000, run O(n^2) loop to find the shortest distance pair

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    int cnt1 = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (array[i]==1) cnt1++;
    }   
    if (cnt1) {
        cout << n-cnt1 << endl;
        return;
    }
    int hcf = array[0];
    for (int i=1; i<n; i++) {
        hcf = gcd(hcf, array[i]);
    }
    if (hcf != 1) {
        cout << -1 << endl;
        return;
    }
    int min_dist = INF;
    for (int i=0; i<n; i++) {
        int hcf = array[i];
        for (int j=i+1; j<n; j++) {
            hcf = gcd(hcf, array[j]);
            if (hcf == 1) {
                min_dist = min(min_dist, j-i);
                break;
            }
        }
    }
    cout << min_dist+(n-1) << endl; // -1 as changes one element to 1
    
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