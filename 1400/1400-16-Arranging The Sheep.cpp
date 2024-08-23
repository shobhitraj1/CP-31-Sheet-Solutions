// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1520/E

#include <bits/stdc++.h>
using namespace std;

// Every sheep must be bought together, so let the fixed sheep be in the middle (in case of even - 2 middles)
// And all the other sheeps are made to bring the near the fixed sheep

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

int func(vector<int>& stars, int mid) {
    // print(stars);
    int cnt = 0;
    int cur = stars[mid]-1;
    for (int i=mid-1; i>=0; i--) {
        cnt += (cur-stars[i]);
        cur--;
    }
    cur = stars[mid]+1;
    for (int i=mid+1; i<stars.size(); i++) {
        cnt += (stars[i]-cur);
        cur++;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    vector<int> stars;
    for (int i=0; i<n; i++) {
        if (input[i]=='*') stars.pb(i+1);
    }
    int m = stars.size();
    if (m==0 || m==1 || m==n) cout << 0 << endl;
    else {
        int mid1 = m/2;
        int mid2 = (m-1)/2;
        int ans1 = func(stars, mid1);
        int ans2 = func(stars, mid2);
        cout << min(ans1, ans2) << endl;
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