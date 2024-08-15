// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1433/D

#include <bits/stdc++.h>
using namespace std;

// find the connected component with smallest size, 
// connect all components' elements to head of this component
// connect all the rest elements of this component to any of the element in other component to maintain connectivity

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

template<typename T>
void printVector(const vector<T> &v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]";
}

template<typename K, typename V>
void print(const map<K, vector<V>> &m) {
    for (const auto &el : m) {
        cout << "{" << el.first << ": ";
        printVector(el.second);
        cout << "} ";
    }
    cout << endl;
}

void solve() {
    int n, input;
    cin >> n;
    vector<int> parent(n);
    map <int, vector<int>> mp;
    for (int i=0; i<n; i++) {
        cin >> parent[i];
        mp[parent[i]].push_back(i+1);
    }   
    
    // print(mp);
    if (mp.size() == 1) {
        cout << "NO" << endl;
        return;
    }
    int miniCC = -1, cnt = INT_MAX;
    for (const auto &el : mp) {
        if (el.second.size() < cnt) {
            cnt = el.second.size();
            miniCC = el.first;
        }
    }
    int tot = 0;
    vector<pair<int, int>> result;
    for (const auto &el : mp) {
        if (el.first != miniCC) {
            for (auto& e1 : el.second) {
                for (auto& elem : mp[miniCC]) {
                    result.emplace_back(e1, elem);
                    tot += 1;
                    break;
                }
            }
        }
    }
    vector<int> vec = mp[miniCC];
    int m = vec.size();
    for (int i=1; i<m; i++) {
        for (const auto &el : mp) {
            if (el.first != miniCC) {
                for (auto& e1 : el.second) {
                    result.emplace_back(e1, vec[i]);
                    tot += 1;
                    break;
                }
            }
            else continue;
            break;
        }
    }
    if (tot > n-1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i=0; i<result.size(); i++) {
            cout << result[i].first << " " << result[i].second << endl;
        }
    }

    
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