// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1872/D

#include <bits/stdc++.h>
using namespace std;

// Assign largest numbers to multiples of x
// Assign smallest numbers to multiples of y
// Numbers assigned to multiples of both doesn't matter

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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int n1 = n/x, n2 = n/y;
    int m = lcm(x, y);
    m = n/m;
    n1 -= m; n2 -= m;
    int sum = 0;
    // add n1 largest numbers and subtract n2 smallest numbers
    m = n-n1;
    int s1 = (n*(n+1))/2 - (m*(m+1))/2;
    sum += s1;
    sum -= ((n2*(n2+1))/2);
    cout << sum << endl;
    
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