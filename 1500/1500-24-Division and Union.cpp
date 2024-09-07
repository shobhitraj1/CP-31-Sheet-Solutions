// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1101/C

#include <bits/stdc++.h>
using namespace std;

// If all the segments have something in common, then not possible => answer = -1
// Else, divide the segments at the point where there is no more intersection
// Take care of the indices as have to return answer according to the input order which will be distorted during sorting

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

bool comp (pair<pair<int,int>, int>& a, pair<pair<int,int>, int>& b) {
    if (a.first.first < b.first.first) return true;
    else return false;
}

void solve() {
    int n, x, y;
    cin >> n;
    vector<pair<pair<int,int>, int>> res;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        res.pb({{x, y}, i});
    }   
    sort(all(res), comp);
    // for (auto elem : res) {
    //     cout << "(" << elem.first.first << ", " << elem.first.second << ") => index = " << elem.second << endl;
    // }
    int index = -1;
    int last = res[0].first.second;
    for (int i=1; i<n; i++) {
        if (res[i].first.first > last) {
            index = i;
            break;
        }
        else last = max(last, res[i].first.second);
    }
    if (index == -1) cout << -1 << endl;
    else {
        vector<int> ans(n, 1);
        for (int i=index; i<n; i++) {
            ans[res[i].second] = 2;
        }
        print(ans);
    }
    
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