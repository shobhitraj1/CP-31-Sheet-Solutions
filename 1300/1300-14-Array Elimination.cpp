// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1601/A

#include <bits/stdc++.h>
using namespace std;

// can group k elements together and make them all zero if each bit set in all the nos. is multiple of k
// hence, take hcf of the no of bit set of all the numbers for each bit 0 to 30.
// and then all k that are factors of this hcf will be able to group array

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
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    int hcf = 0;
    for (int j=0; j<31; j++) {
        int set = 0;
        for (int i=0; i<n; i++) {
            if (array[i]&(1<<j)) set++;
        }
        hcf = gcd(hcf, set);
    }
    if (hcf==0) {
        for (int i=1; i<=n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    set <int> factors;
    for (int i=1; i*i<=hcf; i++) {
        if (hcf%i==0) {
            factors.insert(i);
            factors.insert(hcf/i);
        }
    }
    for (auto elem : factors) {
        cout << elem << " ";
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