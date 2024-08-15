// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1891/B

#include <bits/stdc++.h>
using namespace std;

// Sort according to highest power of 2 divisors
// When add 2^x-1 to all numbers who have highest factor >= 2^x, then highest
// factor of those numbers become 2^x-1, i.e. query-1

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
    int n, q, input;
    cin >> n >> q;
    // vector<int> array(n);
    vector<pair<int, int>> result;
    for (int i=0; i<n; i++) {
        cin >> input;
        result.emplace_back(input,i);
    }   
    map <int, vector<pair<int,int>>> m;
    for (int i=0; i<=30; i++) {
        vector<pair<int,int>> temp;
        m[i] = temp;
    }
    for (int i=0; i<n; i++) {
        auto p = result[i];
        int num = p.first;
        m[log2(num&-num)].push_back(p);
    }
    for (int i=0; i<q; i++) {
        int query;
        cin >> query;
        int m1 = (1<<(query-1));
        for (int j=query; j<=30; j++) {
            for (auto &p : m[j]) {
                p.first += m1;
            }
            m[query-1].insert(m[query-1].end(),m[j].begin(),m[j].end());
            m[j].clear();
        }
    }
    result.clear();
    for (int i=0; i<=30; i++) {
        for (auto &p: m[i]) {
            result.emplace_back(p);
        }
    }
    sort(result.begin(), result.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    for (auto &p : result){
        cout << p.first << " ";
    }
    cout << endl;
    

    
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