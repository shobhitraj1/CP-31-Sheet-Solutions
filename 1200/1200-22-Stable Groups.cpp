// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1539/C

#include <bits/stdc++.h>
using namespace std;

// Sort and create intervals with gaps, sort the gaps
// We have k arbitrary levels to cover the gaps & merge the intervals
/*
Merging two segments with knowledge difference d may be done by adding ⌈d/x⌉−1 new students. 
Each such merge decreases the answer by 1 so we should maximize the amount of merges. 
To do that we should just consider the merges in increasing order of their costs.
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    sort(all(array));
    vector<pair<int,int>> groups;
    vector<int> gaps;
    int start = array[0], end = array[0];
    for (int i=1; i<n; i++) {
        if (array[i]-end<=x) end = array[i];
        else {
            gaps.pb(array[i]-end);
            groups.emplace_back(start, end);
            start = end = array[i];
        }
    }
    groups.emplace_back(start, end);
    int grp = groups.size();
    if (grp == 1) {
        cout << 1 << endl;
        return;
    }
    // print(groups);
    // print(gaps);
    sort(all(gaps));
    int m = gaps.size();
    for (int i=0; i<m; i++) {
        int c;
        if (gaps[i]%x==0) c = gaps[i]/x - 1;
        else c = gaps[i]/x;
        if (c<=k) {
            grp-=1; 
            k-=c;
        }
        else break;
    }
    cout << grp << endl;

    
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