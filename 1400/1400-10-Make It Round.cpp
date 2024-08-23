// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1759/D

#include <bits/stdc++.h>
using namespace std;

// In order to have zeroes in end, need most no of pairs of 2 & 5
// After no more pairs of 2 & 5 can be added, i.e. k*10 exceeds m, 
// in order to increase the final n*k (which has the maximum no of zeroes) can increase k by multiplying it with some no and keeping it within m
// As multiplying by 10 exceeds m, hence try multiplying from 9 to 2 until it exceeds m
// If no zeroes at the end, then output n*m (as asked in the question)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int highestPowDiv(int n, int k) {
    int cnt = 0;
    while (n%k==0) {
        n/=k;
        cnt++;
    }
    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int a = highestPowDiv(n, 2);
    int b = highestPowDiv(n, 5);
    int ans = 1;
    while (a<b) {
        if (ans*2<=m) {
            ans*=2;
            a++;
        }
        else break;
    }
    while (b<a) {
        if (ans*5<=m) {
            ans*=5;
            b++;
        }
        else break;
    }
    for (int i=10; i>=2; i--) {
        while (ans*i<=m) ans*=i;
    }
    if ((n*ans)%10!=0) cout << n*m << endl;
    else cout << n*ans << endl;    
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