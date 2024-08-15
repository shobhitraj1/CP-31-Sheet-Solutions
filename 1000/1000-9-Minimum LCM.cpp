// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1765/M

#include <bits/stdc++.h>
using namespace std;

// n=even --> n/2 n/2
// n=odd --> find smallest factor of n and divide according to that
// For eg. - 9 => 3 6 ; 21 => 7 14 (21/3 & 21*2/3); 25 => 5 20 (25/5 & 25*4/5) = LCM is right number
// 21 => 7 14 (21/3 & 21*2/3) => 3 18 (21/7 & 21*6/7) ... ((n-1)/n) keeps increasing, so for least -> take leftmost
// {((n-1)/n) keeps increasing} => n-1/n < n/n+1 because n^2-1<n^2
// if prime => 1 n-1 => LCM = n-1

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

int smallestFactor(int n) {
    int max = 1;
    for (int i=3; i<=sqrt(n); i+=2) {
        if (n%i==0) return i;
    }
    return max;
}

void solve() {
    int n;
    cin >> n;
    if (n%2==0) cout << n/2 << " " << n/2 << endl;
    else {
        int m = smallestFactor(n);
        if (m==1) cout << 1 << " " << n-1 << endl;
        else cout << n/m << " " << n-(n/m) << endl;
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