// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1183/D

#include <bits/stdc++.h>
using namespace std;

// Sort the candies according the no of candies for each type
// Keep all the candies of the type with largest no of candies
// next greatest candies can't have same no of candies and hence keep either those nos. if less current greatest type or keep (cur-1) candies
// Continue this until all the types get over or candies of some type become 1

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
    map <int, int> mp;
    for (int i=0; i<n; i++) {
        cin >> input;
        mp[input]++;
    }   
    vector<int> items;
    for (auto elem : mp) {
        items.pb(elem.second);
    }
    sort(all(items));
    // print(items);
    int m = items.size();
    int cur = items[m-1]+1;
    int ans = 0;
    for (int i=m-1; i>=0; i--) {
        if (items[i]<cur) {
            ans += items[i];
            cur = items[i];
        }
        else if (items[i]>=cur) {
            ans += (cur-1);
            cur--;
        }
        if (cur==1) break;
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
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}