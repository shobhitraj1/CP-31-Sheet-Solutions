// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1899/C

#include <bits/stdc++.h>
using namespace std;

// Kadane's algorithm with modification to stop if same consecutive parity

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
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    int sum = array[0];
    int maxi = sum;
    for (int i=1; i<n; i++) {
        // cout << maxi << " " << sum << " " << array[i] << endl;
        if (sum < 0) {
            maxi = max(maxi, sum);
            sum = 0;
        }
        if (abs(array[i]%2) == abs(array[i-1]%2)) {
            sum = array[i];
        }
        else {
            sum += array[i];
        }
        maxi = max(maxi, sum);
    }
    cout << maxi << endl;
    
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