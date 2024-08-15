// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1618/C

#include <bits/stdc++.h>
using namespace std;

// HCF of 1,3,5,... elements must not divide any of 2,4,6,...
// HCF of 2,4,6,... elements must not divide any of 1,3,5,...

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
    int hcf1 = 0;
    int hcf2 = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (i%2==0) hcf1 = __gcd(hcf1,array[i]);
        else hcf2 = __gcd(hcf2,array[i]);
    }   
    bool flag1 = true;
    bool flag2 = true;
    for (int i=0; i<n; i+=2) {
        if (array[i]%hcf2==0) {
            flag1 = false;
            break;
        }
    }
    for (int i=1; i<n; i+=2) {
        if (array[i]%hcf1==0) {
            flag2 = false;
            break;
        }
    }
    if (flag1) cout << hcf2 << endl;
    else if (flag2) cout << hcf1 << endl;
    else cout << 0 << endl;
    
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