// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1364/B

#include <bits/stdc++.h>
using namespace std;

// Similar to Contrast Value problem - https://codeforces.com/problemset/problem/1832/C

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
    vector<int> array(n);
    int contrast = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (i>0) contrast += abs(array[i]-array[i-1]);
    }   
    // cout << contrast << endl;
    int cnt = 0;
    vector<int> ans; ans.pb(array[0]);
    int i=1, j=0;
    while (i+1<n) {
        if (abs(array[i]-array[j])+abs(array[i+1]-array[i]) == abs(array[i+1]-array[j])) {
            cnt += 1;
            i+=1;
        }
        else {
            ans.pb(array[i]);
            j=i;
            i+=1;
        }
    }
    // cout << n-cnt << endl;
    ans.pb(array[n-1]);
    cout << ans.size() << endl;
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