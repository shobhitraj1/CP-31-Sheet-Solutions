// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1648/A

#include <bits/stdc++.h>
using namespace std;

// instead of considoring both x & y at once, considor them separately
// store for each color, the indices of x and y at which they occur
// use prefix sum concept to compute the manhattan distance for x's & y's
// For Eg. - color 1 occurs at indices 0, 0, 1, 1, 2, 2
// for 3rd element --> elem * prev_cnt - prev_sum = 1*2 - 0 = 2 (ans += 2)
// for 4th element --> elem * prev_cnt - prev_sum = 1*3 - 1 = 2 (ans += 2) ...

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
    int n, m, input;
    cin >> n >> m;
    // instead of considoring both x & y at once, considor them separately
    map <int, vector<int>> mp_x, mp_y;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> input;
            mp_x[input].pb(i);
            mp_y[input].pb(j);           
        }
    } 
    int ans = 0;
    for (auto elem : mp_x) {
        auto vec = elem.second;
        sort(all(vec));
        // print(vec);
        int sum = 0;
        for (int i=0; i<vec.size(); i++) {
            ans += (vec[i]*i-sum);
            sum += vec[i];
        }
    }
    for (auto elem : mp_y) {
        auto vec = elem.second;
        sort(all(vec));
        // print(vec);
        int sum = 0;
        for (int i=0; i<vec.size(); i++) {
            ans += (vec[i]*i-sum);
            sum += vec[i];
        }
    }
    cout << ans << endl; 

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