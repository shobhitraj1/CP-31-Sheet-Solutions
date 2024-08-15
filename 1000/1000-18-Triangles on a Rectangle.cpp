// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1620/B

#include <bits/stdc++.h>
using namespace std;

// maximum base = range of points & maximum height = the corresponding width or height
// Find the maximum double area = base*height

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

void solve() {
    int w, h, k;
    cin >> w >> h;
    int input, min, max;
    int answer = 0;
    for (int j=0; j<4; j++) {
        cin >> k;
        for (int i=0; i<k; i++) {
            cin >> input;
            if (i==0) min = input;
            if (i==k-1) max = input;
        }
        int base = max - min;
        int height;
        if (j<2) height = h;
        else height = w;
        if (base*height>answer) answer = base*height;

    }

    cout << answer << endl;

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