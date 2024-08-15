// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1541/B

#include <bits/stdc++.h>
using namespace std;

// As a[i]*a[j]=i+j, hence i+j must be multiple of a[i]
// Don't check for all j's just j such that i+j is multiple of a[i]
// As all distinct numbers in array & a[i]<=2*n, total TC = O(nlogn)
// The number of pairs (a,b) such that a⋅b≤x is O(xlogx).

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, input;
    cin >> n;
    vector<int> array(n+1);
    for (int i=1; i<=n; i++) {
        cin >> array[i];
    }   
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        for (int j=array[i]-i; j<=n; j+=array[i]) {
            if (i<j && array[i]*array[j]==i+j) cnt++;
        }
    }
    cout << cnt << endl;    

    /*
    Alternate solution - Loop over all values of ai and aj. Because i+j≤2⋅n, we only care about pairs (ai,aj)
    if ai⋅aj≤2⋅n. The number of such pairs is O(nlogn), so you can brute force all pairs.
    The reason the total number of pairs is O(nlogn) is because if the first element of the pair is x, 
    there are only 2⋅n/x possible values of y. 
    2⋅n/1+2⋅n/2+2⋅n/3+…2⋅n/n=2⋅n(1/1+1/2+1/3…1/n)=O(nlogn) by the harmonic series. Thus the solution runs in O(nlogn) time total.
    */

    // map <int, int> mp;
    // int cnt = 0;
    // for (int i=0; i<n; i++) {
    //     cin >> input;
    //     for (auto& elem : mp) {
    //         if (elem.first*input>2*n) break;
    //         if (elem.first*input == elem.second+i+1) cnt++;
    //     }
    //     mp[input]=i+1;
    // }   
    // cout << cnt << endl;
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