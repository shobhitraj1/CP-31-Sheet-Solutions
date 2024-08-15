// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1704/C

#include <bits/stdc++.h>
using namespace std;

// compute the inbetween houses in the gaps that are non infected
// first save the ones that are large gaps, sort the gaps/use pq
// each time save a gap, lost 1 in that gap & 2 in all other gaps
// if only 1 in the gap, saved that (as save before infection spreads)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T>
void print(priority_queue<T> v) {
    while(!v.empty()) {
        cout << v.top() << " "; 
        v.pop();
    }
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> array(m);
    for (int i=0; i<m; i++) {
        cin >> array[i];
    }   
    if (m==1) {
        // base case
    }
    sort(all(array));
    priority_queue<int> pq;
    for (int i=1; i<m; i++) {
        pq.push(array[i]-array[i-1]-1);
    }
    int lastGap = (array[0]-1)+(n-array[m-1]);
    pq.push(lastGap);
    // print(pq);
    int cnt = 0, ans = 0;
    while(!pq.empty()) {
        int elem = pq.top(); pq.pop();
        elem -= (2*cnt);
        if (elem<=1) {
            if (elem==1) ans+=1;
            break;
        }
        else {
            ans += (elem-1);
            // cout << ans << endl;
        }
        cnt+=2;
    }
    cout << n-ans << endl;

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