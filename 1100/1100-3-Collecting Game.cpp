// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1904/B

#include <bits/stdc++.h>
using namespace std;

// Sort and 2 pointers approach, use precomputed prefix sum

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
    int n, input;
    cin >> n;
    vector<pair<int, int>> result;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> input;
        array[i] = input;
        result.emplace_back(input, i);
    }   
    sort(all(result)); sort(all(array));
    // print(result);
    vector<int> ans(n, 0);
    int cnt = 0, j = 0;
    for (int i=0; i<n; i++) {
        if (i<j) {
            ans[result[i].second] = j-1;
            continue;
        }
        while (j<n) {
            cnt += array[j];
            j++; 
            if (j==n || array[j]>cnt) break;
        }
        ans[result[i].second] = j-1;
    }
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