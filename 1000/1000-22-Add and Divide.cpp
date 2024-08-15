// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1485/A

#include <bits/stdc++.h>
using namespace std;

// if better to increase b, then increase b first & then divide by A
// can check better or not by taking log_(b) & log_(b+1) 

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
    int a, b;
    cin >> a >> b;
    if (a<b) cout << 1 << endl;
    else if (a==b) cout << 2 << endl;
    else {
        int count = 0;
        if (b==1) {
            b+=1;
            count+=1;
        }
        bool flag = false;
        while (a!=0) {
            int m1 = log2(a)/log2(b);
            int m2 = log2(a)/log2(b+1);
            while (m1>m2) {
                if (a==b+1) {
                    count+=2;
                    flag = true;
                    break;
                }
                b+=1;
                count+=1;
                m1 = log2(a)/log2(b);
                m2 = log2(a)/log2(b+1);
            }
            if (flag) break;
            // cout << a << " " << b << endl;
            a/=b;
            count+=1;
        } 
        cout << count << endl;
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