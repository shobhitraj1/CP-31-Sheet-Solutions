// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1832/B

#include <bits/stdc++.h>
using namespace std;

// greedily check will not give correct ans as mutating, may give better than if select
// min(2 mins, max), in the next go the min was really low
// For eg. - 10 11 12 13 15 22 (k=2), better to remove 22 and 15, grredy is wrong here
// Hence, check every possible - use prefix sum to optimize

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    sort(all(array));
    // print(array);

    for (int i=1; i<n; i++) {
        array[i]+=array[i-1];
    }
    // print(array);

    int maxSum = array[n-(k+1)]; // 0 times removing 2 mins (k times removing max)
    // check for all possibilities of k operations
    // 0 times remove 2 mins TO k times remove 2 mins (given constraint 2k<n)
    // if i time remove 2 mins, then (k-i) time remove max
    for (int i=1; i<=k; i++) {
        maxSum = max(array[(n-1)-(k-i)] - array[i*2-1], maxSum);
    }
    cout << maxSum << endl;
   
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}