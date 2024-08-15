// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1411/B

#include <bits/stdc++.h>
using namespace std;

// Worst Case number is fair if it is divisible by each of the numbers 1..9. 
// LCM (1...9) = 2520. Therefore, any multiple of 2520 will always by fair number.
// Hence, x will always be within <= n+2520
// Just loop till 2520, increase one each time and check brute force if fair
// Determine if the number is fair by checking each of its digits separately.

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

// Function to check if a number is fair
bool isFair(int num) {
    string numStr = to_string(num);
    for (char c : numStr) {
        int digit = c - '0';
        if (digit != 0 && num % digit != 0) {
            return false;
        }
    }
    return true;
}

int findMinimumFairNumber(int n) {
    int x = n;
    while (!isFair(x)) {
        x++;
    }
    return x;
}

void solve() {
    int n;
    cin >> n;
    cout << findMinimumFairNumber(n) << endl; 
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