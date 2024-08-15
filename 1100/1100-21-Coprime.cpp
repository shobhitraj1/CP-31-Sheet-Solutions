// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1742/D

#include <bits/stdc++.h>
using namespace std;

// Brute force will give TLE (O(n^2))
// Given constraint a_i<=1000, store the highest index for each value appearing in the array
// Then, brute force in this array & find the highest pair that are coprime --> O(n+1000^2)

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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int n, input;
    cin >> n;
    vector<int> array(1001,-1);
    for (int i=1; i<=n; i++) {
        cin >> input;
        array[input] = i;
    }  

    int ans = -1;
    for (int i=1; i<1001; i++) {
        for (int j=1; j<1001; j++) {
            if (array[i]!=-1 && array[j]!=-1 && __gcd(i,j)==1) 
                ans = max(ans, array[i]+array[j]);
        }
    }
    cout << ans << endl;



    // int ans = -1;
    // for (int i=n-1; i>=0; i--) {
    //     for (int j=i; j>=0; j--) {
    //         if (i+j+2<ans) break;
    //         if (gcd(array[i],array[j])==1) {
    //             ans = max(ans,i+j+2);
    //         }
    //     }
    // } 
    // cout << ans << endl;

    
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