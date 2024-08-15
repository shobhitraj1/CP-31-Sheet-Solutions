// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1876/A

#include <bits/stdc++.h>
using namespace std;

// always keep choosing the minimum cost (including pak's cost) (till we can - check limited no of shares)

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
    int n, p, a, b;
    cin >> n >> p;
    vector<int> shares(n);
    vector<int> costs(n);
    vector<pair<int, int>> result;
    for (int i=0; i<n; i++) {
        cin >> shares[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> costs[i];
        result.emplace_back(shares[i],costs[i]);
    }   
    int count = 0;
    int cost = 0;
    count += 1; cost += p; // first share by Pak Chanek

    // Sort the pairs in decreasing order of the cost
    sort(result.begin(), result.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    // print(result);
    while (count != n) {
        if (result.back().second>=p) {
            break;
        }
        if (result.back().first+count>n) {
            cost += (result.back().second*(n-count));
            count += (n-count);
        }
        else {
            count += result.back().first;
            cost += (result.back().first*result.back().second);
            result.pop_back();
        }
    }

    if (count!=n) {
        int rem = n-count;
        count += rem;
        cost += (p*rem);
    }

    cout << cost << endl;  

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}