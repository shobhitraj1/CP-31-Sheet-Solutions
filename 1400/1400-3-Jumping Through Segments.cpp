// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1907/D

#include <bits/stdc++.h>
using namespace std;

// FFFFTTTTT --> Predicate function (need to find the first true) => Binary Search
/*
To check whether it is possible to pass the level with a certain k, we will maintain a segment in which we can find ourselves. 
After each move, it expands by k in both directions and is reduced to the intersection with the segment where the player must be at that move. 
If at any point the intersection becomes empty [range becomes -ve (left>right)], then it is impossible to pass the level with such k.
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

bool isSufficient(vector<pair<int, int>>& segments, int k) {
    int n = segments.size();
    int cur_left = 0, cur_right = 0; // range
    for (int i=0; i<n; i++) {
        cur_left = max(cur_left-k, segments[i].first);
        cur_right = min(cur_right+k, segments[i].second);
        if (cur_left > cur_right) return false; // range not possible (can't jump)
    }
    return true;    
}

void solve() {
    int n, l, r;
    cin >> n;
    vector<pair<int, int>> segments;
    int maxi = 0;
    for (int i=0; i<n; i++) {
        cin >> l >> r;
        segments.emplace_back(l, r);
        maxi = max(maxi, r);
    }   
    // FFFFTTTTT --> need the first true (smallest k)
    int low = 0;
    int high = maxi;
    while (high-low>1) {
        int mid = low + (high-low)/2;
        if (isSufficient(segments, mid)) high = mid;
        else low = mid+1;
    }
    if (isSufficient(segments, low)) cout << low << endl;
    else if (isSufficient(segments, high)) cout << high << endl;
    else cout << -1 << endl; // will never reach
    
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