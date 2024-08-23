// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1513/B

#include <bits/stdc++.h>
using namespace std;

// As the property of AND is such that it can't exceed the elements in the sequence, i.e. AND of [a1...an] is always <= a_i
// Array is good if first element = last element = AND of first to i-th element = AND of all elements
// As AND of all elements is set as first, therefore all the next (i-1) elements don't set any extra bit and hence all of them can be arranged in (n-2)! ways
// And if there are k elements = AND, then 2*kC2 ways to arrange first and last elements 

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;
const int N = 2e5 + 10;

int fact[N];

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    map <int, int> mp;
    int and_;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        mp[array[i]]++;
        if (i==0) and_ = array[i];
        else and_ &= array[i];
    }   
    int k = mp[and_];
    int ans = (((k*(k-1))%MOD) * fact[n-2])%MOD;
    cout << ans << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    fact[0] = fact[1] = 1;
    for (int i=2; i<N; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}