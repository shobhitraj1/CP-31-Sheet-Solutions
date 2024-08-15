// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1511/C

#include <bits/stdc++.h>
using namespace std;

// As only 50 colors & always need the minimum index
// Maintain an array & only store the minimum index of each color 
// If queried, every less than that is shifted to right & it's minimum is made 1
// O(n+q*50)-time

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
    int n, q, input, query;
    cin >> n >> q;
    vector<int> array(51, -1);
    for (int i=1; i<=n; i++) {
        cin >> input;
        if (array[input]==-1) array[input]=i;
    }   
    vector<int> res;
    for (int i=0; i<q; i++) {
        cin >> query;
        res.pb(array[query]);
        for (int j=1; j<51; j++) {
            if (array[j]<array[query] && array[j]!=-1) {
                array[j]+=1;
            }
        }
        array[query] = 1;
    }
    print(res);


    
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