// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1561/C

#include <bits/stdc++.h>
using namespace std;

// for each cave, find the minimum points needed to start, and will have in the end
// sort and start from the minimum cave, if extra is needed, add the diff to start & adjust endpoints accordingly

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

void solve() {
    int n, k, monster;
    cin >> n;
    vector<vector<int>> caves(n);
    vector<pair<int, int>> result; // {start, end}
    for (int i=0; i<n; i++) {
        cin >> k;
        int maxPower = INT_MIN;
        for (int j=0; j<k; j++) {
            cin >> monster;
            caves[i].pb(monster);
            maxPower = max(maxPower, monster+1-j);
        }
        result.emplace_back(maxPower, maxPower+k);
    }   
    sort(all(result));
    // print(result);
    int start = result[0].first, end = result[0].second;
    int extra = 0, maxStart = 0;
    for (int i=1; i<n; i++) {
        // cout << start << " " << end << endl;
        if (result[i].first>end) {
            start += (result[i].first-end);
            end = result[i].second;
        }
        else {
            end += (result[i].second-result[i].first);
        }
    }
    cout << start << endl;
    
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