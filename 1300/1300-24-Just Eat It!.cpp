// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1285/B

#include <bits/stdc++.h>
using namespace std;

// if subsegment sum exceeds total array sum s.t. subsegment is not entire array, then NO
// use Kadane's algorithm with start & end indices

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    int yasser = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        yasser += array[i];
    }   
    int sum = 0, start = 0, end = 0, maxi = INT_MIN;
    for (int i=0; i<n; i++) {
        sum += array[i];
        if (sum>maxi) {
            maxi = sum;
            end = i;
        }
        if (sum<=0) {
            sum = 0;
            start = i+1;
        }
    }
    if (maxi >= yasser && (start!=0 || end!=(n-1))) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
    
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