// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1883/C

#include <bits/stdc++.h>
using namespace std;

// brute force for k = 2, 3, 5 - find the lowest (k - remainder when divided by 5)
// for k = 4, minimum can by 4 or by 2 two's (Hence, ans can be [0,2])

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    vector<int> array1(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
        array1[i] = array[i];
    }   

    for (int i=0; i<n; i++) {
        array[i] %= k;
        if (array[i]!=0) array[i] = k-array[i];
    }
    int minimum = 11;
    for (int i=0; i<n; i++) {
        if (array[i]<minimum) minimum = array[i];
    }

    if (k!=4) cout << minimum << endl;
    else {
        for (int i=0; i<n; i++) {
            array1[i] %= 2;
            if (array1[i]!=0) array1[i] = 2-array1[i];
        }
        int min1 = 11, min2 = 12;
        int index = -1;
        for (int i=0; i<n; i++) {
            if (array1[i] < min1) {
                min1 = array1[i];
                index = i;
            }
        }
        array1[index] = 20;
        for (int i=0; i<n; i++) {
            if (array1[i]<min2) min2 = array1[i];
        }
        int sum = min1 + min2;
        cout << min(minimum,sum) << endl;
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}