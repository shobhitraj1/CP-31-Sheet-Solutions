// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1913/B

#include <bits/stdc++.h>
using namespace std;

// just swap the 0s and 1s and then from left to right, remove if same
// if remove (i-=1), to check again if the new char is not same

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    string input1; // original string
    cin >> input1;
    string input = input1;
    int n = input.length();
    int count0 = 0, count1 = 0;
    for (int i=0; i<n; i++) {
        if (input[i]=='0') count0+=1;
        else count1+=1;
    }
    if (count0==0 || count1==0) {
        cout << n << endl;
        return;
    }
    if (count0 == count1) {
        cout << 0 << endl;
        return;
    }
    int change0 = 0, change1 = 0;
    for (int i=0; i<n; i++) {
        if (input[i]=='0' && change0 < count1) {
            input[i] = '1';
            change0+=1;
        }
        else if (input[i]=='1' && change1 < count0) {
            input[i] = '0';
            change1+=1;
        }
    }
    // cout << input1 << " " << input << endl;
    int count = 0;
    for (int i=0; i<input.length(); i++) {
        if (input[i]==input1[i]) {
            input.erase(i, 1);
            i-=1;
            count+=1;
        }
    }
    cout << count << endl;
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