// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1848/B

#include <bits/stdc++.h>
using namespace std;

// Very similar to Virus problem - https://codeforces.com/problemset/problem/1704/C
// For each color, the lengths of the two maximum steps (gap) between planks of that color.
// We need to consider that we can repaint one of the planks. Let's say we repaint a plank in color c. 
// It is easy to notice that we should repaint the plank in the middle of the longest step between planks of color c.
// Therefore, the answer for a fixed color will be the maximum of two values: half the length of the longest step between planks of that color, 
// and the length of the second largest step between planks of that color.
// Knowing the answer for each individual color, take minimum for all the colors which will be the answer.

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
    int n, k, input;
    cin >> n >> k;
    map <int, vector<int>> mp;
    for (int i=0; i<n; i++) {
        cin >> input;
        mp[input].pb(i+1);
    }   
    int mini = INT_MAX;
    for (auto& elem : mp) {
        auto& vec = elem.second;
        sort(all(vec));
        int m = vec.size();
        priority_queue<int> pq;
        for (int i=1; i<m; i++) {
            pq.push(vec[i]-vec[i-1]-1);
        }
        pq.push(vec[0]-1); pq.push(n-vec[m-1]);
        int top = pq.top(); pq.pop();
        pq.push(top/2);
        mini = min(mini, pq.top());
    }
    cout << mini << endl;
    
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