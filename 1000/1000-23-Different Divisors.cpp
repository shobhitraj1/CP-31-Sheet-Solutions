// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1474/B

#include <bits/stdc++.h>
using namespace std;

// 1 a(>=1+n) b(>=a+n) a*b
// both of them middle nos. should be prime

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

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    int a = 1+n;
    while (!isPrime(a)) {
        a+=1;
    }
    int b = a+n;
    while (!isPrime(b)) {
        b+=1;
    }
    cout << a*b << endl;    
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