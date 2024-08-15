// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1614/B

#include <bits/stdc++.h>
using namespace std;

// n=odd --> -n/2 ... 0 ... n/2 (n+1)/2
// n=even --> -n/2 ... 0 ... n/2
// Sort the visits count & then multiply by them the biggest distance gaps first
// To make it minimum, greedy approach - Max gap should have minimum visits

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
    int n;
    cin >> n;
    vector<int> array(n);
    // Creating a vector of pairs (value, index)
    vector<pair<int, int>> result;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        result.emplace_back(array[i], i + 1); // (value, 1-based index)
    }   

    stable_sort(all(array), [](int a, int b) { return a > b; }); 

    // Sort the pairs in decreasing order of the values
    stable_sort(result.begin(), result.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });
    // print(result);

    int sum = 0;
    for (int i=0; i<n; i+=2) {
        result[i].first = (i/2)+1;
        sum += abs((result[i].first)*array[i]);
        if (i+1<n) {
            result[i+1].first = -((i/2)+1);
            sum += abs((result[i+1].first)*array[i+1]);
        }
    }
    // print(result);
    cout << sum*2 << endl;
    // Sort the pairs in increasing order of the indices
    sort(result.begin(), result.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    cout << 0 << " ";
    for (const auto &el : result) {
        cout << el.first << " ";
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}