// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1504/B

#include <bits/stdc++.h>
using namespace std;

// Inverting won't change the equality of no of zeroes/ones in the prefixes
// Traverse from right to left and if unequal (after inverting cnt times) & 
// equal no of zeroes & ones - can reverse again, else not possible

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
    string a, b;
    cin >> a >> b;
    vector<int> zeroes(n, 0), ones(n, 0);
    for (int i=0; i<n; i++) {
        if (a[i]=='1') ones[i]+=1;
        else zeroes[i]+=1;
        if (i>0) {
            ones[i]+=ones[i-1]; 
            zeroes[i]+=zeroes[i-1];
        }
    }
    // print(zeroes); print(ones);
    int cnt = 0;
    for (int i=n-1; i>=0; i--) {
        char new_ai = a[i];
        if (cnt&1) new_ai = (new_ai=='0') ? '1' : '0';
        if (new_ai!=b[i]) {
            if (ones[i]!=zeroes[i]) {
                cout << "NO" << endl;
                return;
            }
            else cnt++;
        }
    }
    cout << "YES" << endl;

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