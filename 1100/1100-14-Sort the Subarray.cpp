// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1821/B

#include <bits/stdc++.h>
using namespace std;

// Just find the maximum length of sorted subarray in a' but with condition
// given a' ≠ a, i.e. that max subarray shouldn't have the same elements as a[i]

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
    vector<int> A(n+1);
    vector<int> B(n+1);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }   
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }   
    // find the maximum length of sorted subarray
    int max = 0;
    int index = 0;
    int count = 1;
    int sameCount = 1;
    B[n]=0;
    for (int i=1; i<=n; i++) {
        if (B[i]>=B[i-1]) {
            count+=1;
            if (B[i]==A[i]) sameCount+=1;
            else sameCount = 1;
        }
        else {
            if (count>max && sameCount!=count) {
                max = count;
                index = i-count;
            }
            count = 1;
            sameCount = 1;
        }
    }

    cout << index+1 << " " << index+max << endl;
    
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