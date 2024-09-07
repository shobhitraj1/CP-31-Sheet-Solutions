// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1891/C

#include <bits/stdc++.h>
using namespace std;

// Use the points by smaller one to remove the larger one and remove it in one instance, not by part by part
// Sort and use 2 pointers

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
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    sort(all(array));
    // print(array);
    int i = 0, j = n-1;
    int cur = 0;
    int ans = 0;
    while (i < j) {
        if (cur + array[i] == array[j]) {
            cur = 0;
            ans += (array[i]+1); i++; j--; 
        }
        else if (cur + array[i] > array[j]) {
            array[i] -= (array[j]-cur);
            ans += (array[j]-cur+1);
            cur = 0;
            j--;
        }
        else {
            cur += array[i];
            ans += array[i]; i++; 
        }
        // cout << i << " " << j << " " << cur << " " << ans << endl;
    }
    if (i==j) {
        int needed = (array[j]-cur+1)/2;
        ans += (needed+1);
        if (array[j]==1 && cur==0) ans-=1;
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