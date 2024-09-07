// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/976/C

#include <bits/stdc++.h>
using namespace std;

// Sort according to the x coordinate so that when iterated through, left end of the segment is always contained
// For the right end, sort using customized comparator so that keep track of maximum y coordinate & check if lies within

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

bool comp (pair<pair<int,int>, int>& a, pair<pair<int,int>, int>& b) {
    if (a.first.first < b.first.first) return true;
    else if (a.first.first == b.first.first) {
        if (a.first.second > b.first.second) return true;
        else return false;
    }
    else return false;
}

void solve() {
    int n, x, y;
    cin >> n;
    vector<pair<pair<int,int>, int>> res;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        res.pb({{x,y}, i+1});
    }   
    sort(all(res), comp);
    int last = res[0].first.second;
    int index = res[0].second;
    for (int i=1; i<n; i++) {
        if (res[i].first.second <= last) {
            cout << res[i].second << " " << index << endl;
            return;
        }
        last = res[i].first.second;
        index = res[i].second;
    }
    cout << -1 << " " << -1 << endl;

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