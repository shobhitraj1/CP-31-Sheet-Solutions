// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1850/E

#include <bits/stdc++.h>
using namespace std;

// Find w using binary search b/t 1 and sqrt((c-a)/4)
// Take care of integer overflow

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, c, x;
    cin >> n >> c;
    int a = 0; 
    int b = 0;
    for (int i=0; i<n; i++) {
        cin >> x;
        a+=(x*x);
        b+=x;
    }
    int low = 1;
    int high = sqrt((c-a)/4);
    int mid;
    // cout << a << " " << b << endl;
    
    while (low<=high) {
        mid = low + (high-low)/2;
        if (4*mid*n > INF/mid) {
            high = mid-1;
            continue;            
        }
        if (a+4*b*mid+4*mid*mid*n < c) low = mid+1;
        else if (a+4*b*mid+4*mid*mid*n == c) break;
        else high = mid - 1;
    }

    cout << mid << endl;   
    
    
    // int x;
    // int a = 0; 
    // int b = 0;
    
    // for (int i=0; i<n; i++){
    //     cin >> x;
    //     a+=(x*x);
    //     b+=x;
    // }
    // // cout << a << " " << b << endl;
    // // quadratic equation => 4nw^2 + 4wb + a = c;
    // int A = 4*n;
    // int B = 4*b;
    // int C = a-c;
    // int w = (-B + sqrt(B*B-4*A*C))/(2*A);
    // cout << w << endl;

    
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