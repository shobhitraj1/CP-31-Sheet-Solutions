// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1869/B

#include <bits/stdc++.h>
using namespace std;

// either go via major cities OR can also go directly 

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
    int n, k, x, y, first, last;
    cin >> n >> k >> first >> last;
    vector<pair<int, int>> result;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        result.emplace_back(x,y);
    }   
    if (first<=k && last<=k) {
        cout << 0 << endl;
        return;
    }
    if (first==last) {
        cout << 0 << endl;
        return;
    }
    if (k==0) {
        cout << abs(result[first-1].first-result[last-1].first)+abs(result[first-1].second-result[last-1].second) << endl;
        return;
    }

    int i = first-1;
    int shortest = INF;
    for (int j=0; j<k; j++) {
        shortest = min(shortest, abs(result[i].first-result[j].first)+abs(result[i].second-result[j].second));
    }
    int firstMajor=shortest;
    i = last-1;
    shortest = INF;
    for (int j=0; j<k; j++) {
        shortest = min(shortest, abs(result[i].first-result[j].first)+abs(result[i].second-result[j].second));
    }
    int lastMajor=shortest;

    // print(result);

    int ans;
    if (firstMajor==INF && lastMajor==INF) ans = abs(result[first-1].first-result[last-1].first)+abs(result[first-1].second-result[last-1].second);
    else ans = min(firstMajor+lastMajor,abs(result[first-1].first-result[last-1].first)+abs(result[first-1].second-result[last-1].second));
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}