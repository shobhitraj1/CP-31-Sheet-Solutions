// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1857/D

#include <bits/stdc++.h>
using namespace std;

// Here, path will always be direct because if A->B exists and B->C exists, then A->C definitely exists
// Only strong if path to all the vertices i.e. a[i]-b[i] greater than or equal to all other n-1 a[i]-b[i]'s.

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
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }   
    vector<pair<int, int>> res;
    for (int i=0; i<n; i++) {
        res.emplace_back(A[i]-B[i], i+1);
    }
    sort(all(res));
    vector<int> ans;
    int maxi = res[n-1].first, cnt = 0;
    for (int i=n-1; i>=0; i--) {
        if (res[i].first==maxi) {
            ans.pb(res[i].second);
            cnt++;
        }
        else break;
    }
    cout << cnt << endl;
    sort(all(ans));
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