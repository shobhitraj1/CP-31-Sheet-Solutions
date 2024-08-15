// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1791/G1

#include <bits/stdc++.h>
using namespace std;

// Find cost for each teleport using array[i]+i
// Only keep taking minimum till all coins used
// Use prefix sum to optimize & binary search

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

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

void solve() {
    int n, coins;
    cin >> n >> coins;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
        array[i]+=(i+1);
    }   
    sort(all(array));
    // print(array);
    // find max index such that sum uptill index <= coins --> use prefix sum

    for (int i=1; i<n; i++) {
        array[i]+=array[i-1];
    }
    // print(array);
    // Get an iterator pointing to the first element that is greater than the coins
    auto it = upper_bound(array.begin(), array.end(), coins);
    // If the iterator points to the first element, no element is <= target
    if (it == array.begin()) {
        cout << 0 << endl;
        return;
    }

    // Otherwise, move the iterator one step back to get the largest element <= target
    --it;
    // Return the index of that element
    int ans = distance(array.begin(), it);
    cout << ans+1 << endl;
    
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