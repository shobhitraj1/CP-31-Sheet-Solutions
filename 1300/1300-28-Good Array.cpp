// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1077/C

#include <bits/stdc++.h>
using namespace std;

// just remove, i.e. subtract from total sum & check if remaining_sum/2 exists in remaining array or not

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
    multiset<int> ms;
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        ms.insert(array[i]);
        sum += array[i];
    }   
    // cout << "sum = " << sum << endl;
    vector<int> ans;
    for (int i=0; i<n; i++) {
        int elem = array[i];
        int newSum = sum - elem;
        if (newSum&1) continue;
        int s = newSum/2;
        if (elem != s && ms.count(s)) ans.pb(i+1);
        else if (elem == s && ms.count(s)>1) ans.pb(i+1);
    }
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}