// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1807/G2

#include <bits/stdc++.h>
using namespace std;

// sort the array to kind of obtain the order in which element inserted
// first 2 elements should always be 1,1
// then, total sum of the array, any element <= sum can be made & added in that array
// As, have enough quantity of 1's, or thir sum only

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
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    if (n==1) {
        if (array[0]==1) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    if (n==2) {
        if (array[0]==1 && array[1]==1) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    sort(all(array));
    if (array[1]!=1) {
        cout << "NO" << endl;
        return;
    }
    vector<int> sum = array;
    for (int i=1; i<n; i++) {
        sum[i]+=sum[i-1];
    }
    bool flag = true;
    for (int i=2; i<n; i++) {
        if (array[i]>sum[i-1]) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    
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