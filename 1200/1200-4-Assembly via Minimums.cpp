// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1857/C

#include <bits/stdc++.h>
using namespace std;

// Sort B first in a map, and we will know how many times each element is minimum
// Start from the largest no, first add the largest no to the array, and then cnt the no of elements already added
// subtract those from the no being considored and add that element to array (until its requirement becomes 0)
// Then, reverse the answer in the end, as processed in backward order

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
    int n, input;
    cin >> n;
    int m = (n*(n-1))/2;
    map <int, int> mp;
    for (int i=0; i<m; i++) {
        cin >> input;
        mp[input]++;
    }   
    int cnt = 1;
    vector<int> ans;
    ans.push_back((--mp.end())->first);
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        while (it->second>0) {
            ans.pb(it->first);
            it->second -= cnt;
            cnt++;
        }
    }
    reverse(all(ans));
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