// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1701/C

#include <bits/stdc++.h>
using namespace std;

// first calculate the time if all workers are assigned to their own task
// Then, sort them according to their time taken, and then distribute the longest time to shortest time
// Keep doing this until diff(longest-smallest)>2, 
// As m > n, this will make sure that all the tasks are also completed as none of them will have 0 workers (0 time) assigned to them

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, m, input;
    cin >> n >> m;
    vector<int> array(n, 0);
    for (int i=0; i<m; i++) {
        cin >> input;
        array[input-1]++;
    }   
    multimap<int, pair<int, int>> mp;
    for (int i=0; i<n; i++) {
        mp.insert({array[i], {array[i], 0}});
    }
    // for (auto elem : mp) {
    //     cout << elem.first << " = {" << elem.second.first << ", " << elem.second.second << "}\n";
    // }
    while (true) {
        if ((--mp.end())->first - mp.begin()->first <= 2) break;
        int first_own = mp.begin()->second.first; 
        int first_other = mp.begin()->second.second;
        int last_own = (--mp.end())->second.first;
        int last_other = (--mp.end())->second.second;
        mp.erase(mp.find(mp.begin()->first));
        mp.erase(mp.find((--mp.end())->first));
        if (last_own) {
            first_other++;
            last_own--;
        }
        else {
            first_other++;
            last_other--;
        }
        mp.insert({first_own+first_other*2, {first_own, first_other}});
        mp.insert({last_own+last_other*2, {last_own, last_other}});
    }
    int ans = 0;
    for (auto elem : mp) {
        ans = max(ans, elem.first);
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