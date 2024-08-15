// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1915/E

#include <bits/stdc++.h>
using namespace std;

/*
It's clear that we need to find if there is a subarray with alternating sum equal to 0.
How to check this? Let's flip all elements on even indices a2→−a2,a4→−a4,…. 
Then alternating sums of [a1,a2,a3,a4,…] are the same as subarray sums on [a1,−a2,a3,−a4,…].
So we just need to check if there is a subarray with sum 0. 
This is a standard problem with prefix sums: if two prefix sums are equal or any prefix sum is 0, then the subarray between them has sum 0; 
otherwise, no subarray has sum 0.
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

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
    for (int i=0; i<n; i+=2) {
        array[i]*=(-1);
    }
    for (int i=1; i<n; i++) {
        array[i] += array[i-1];
    }
    sort(all(array));
    string output = "NO";
    for (int i=1; i<n; i++) {
        if (array[i]==0) {
            output = "YES";
            break;
        }
        if (array[i]==array[i-1]) {
            output = "YES";
            break;
        }
    }
    cout << output << endl;
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