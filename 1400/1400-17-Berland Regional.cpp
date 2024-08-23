// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1519/C

#include <bits/stdc++.h>
using namespace std;

// For each team size k, will send the highest top multiple_candidates from each team i.e. multiple of k

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
    int n, strength;
    cin >> n;
    vector<int> univ(n);
    for (int i=0; i<n; i++) {
        cin >> univ[i];
    }   
    map <int, vector<int>> mp;
    for (int i=0; i<n; i++) {
        cin >> strength;
        mp[univ[i]].pb(strength);
    }
    vector<int> team_size(n, 0);
    for (auto elem : mp) {
        int univ = elem.first;
        auto& vec = elem.second;
        sort(all(vec));
        reverse(all(vec)); // select the top candidates (sort in desc order)
        int m = vec.size();
        for (int i=1; i<m; i++) {
            vec[i]+=vec[i-1];
        }
        // print(vec);
        for (int i=1; i<=m; i++) {
            int high = m - (m%i);
            team_size[i-1] += vec[high-1];
        }
    }
    print(team_size);

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