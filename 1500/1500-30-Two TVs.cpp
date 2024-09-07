// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/845/C

#include <bits/stdc++.h>
using namespace std;

// Like N-meetings in one room, sort according to start time or end time (we will proceed with end time)
// Then assign the movies to the TV according to their ending time (i.e. if start time of cur. movie > end time of TV)
// If not possible to assign to any TV, then not possible => output NO
// Also try to assign first to the TV that ends later, so that later when if some movie with smaller start time comes, 
// it can be assigned to the TV with smaller end time if possible (This needs to be done in the end time sorting approach)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

void solve() {
    int n, s, e;
    cin >> n;
    vector<pair<int, int>> res;
    for (int i=0; i<n; i++) {
        cin >> s >> e;
        res.emplace_back(s, e);
    }   
    // sort(all(res), comp);
    sort(all(res));
    int end1 = -1, end2 = -1;
    string output = "YES";
    for (int i=0; i<n; i++) {
        if (res[i].first > end1) {
            end1 = res[i].second;
        }
        else if (res[i].first > end2) {
            end2 = res[i].second;
        }
        else output = "NO";
        // if (end1 < end2) swap(end1, end2);
    }
    cout << output << endl;
   
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