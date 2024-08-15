// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1612/C

#include <bits/stdc++.h>
using namespace std;

// Binary Search in which half it lies

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int k, x;
    cin >> k >> x;
    int incr = (k*(k+1))/2;
    if (incr > x) {
        // cout << "in increasing part" << endl;
        int low = 1;
        int high = k;
        while (high-low>1) {
            int mid = (low+high)/2;
            int sum = (mid*(mid+1))/2;
            if (sum>=x) high = mid;
            else low = mid+1;
        }
        int lowSum = (low*(low+1))/2, highSum = (high*(high+1))/2;
        if (lowSum>=x) cout << low << endl;
        else cout << high << endl;
    }
    else {
        x -= incr;
        if (x==0) {
            cout << k << endl;
            return;
        }
        // cout << "in decreasing part" << endl;
        int decr = (k*(k-1))/2;
        int low = k-1;
        int high = 0;
        while (low-high>1) {
            int mid = (low+high)/2;
            int tempSum = (mid*(mid+1))/2;
            if (decr-tempSum<x) low = mid;
            else high = mid;
        }
        int lowSum = (low*(low+1))/2, highSum = (high*(high+1))/2;
        if (decr-lowSum>=x) cout << k+(k-1)-low << endl;
        else cout << k+(k-1)-high << endl;
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

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}