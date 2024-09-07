// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1466/D

#include <bits/stdc++.h>
using namespace std;

// Have to find non leaf vertices that are largest weights and color the edge connecting to them, 
// so add non leaf vertex with largest weight to the sum
// For k=1, starting sum = sum of weights of all vertices (subtract 1 from degree of each vertex, thus removing leaf nodes)
// Then, according to decreasing order of weights of vertices such that edge left connecting to them, add their weight to the sum

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n, u, v;
    cin >> n;
    vector<int> weights(n+1);
    int sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> weights[i];
        sum += weights[i];
    }   
    map <int, int> mp;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        mp[u]++;
        mp[v]++;
    }
    vector<pair<int, int>> vec;
    for (auto elem : mp) {
        vec.emplace_back(weights[elem.first], elem.second-1);
    }
    sort(all(vec));
    vector<int> ans;
    ans.pb(sum);
    for (int i=vec.size()-1; i>=0; i--) {
        while (vec[i].second>0) {
            sum += vec[i].first;
            vec[i].second--;
            ans.pb(sum);
        }
    }
    print(ans);
    
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