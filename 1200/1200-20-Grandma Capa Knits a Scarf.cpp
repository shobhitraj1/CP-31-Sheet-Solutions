// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1582/C

#include <bits/stdc++.h>
using namespace std;

// Similar to kalindromic array problem --> https://codeforces.com/problemset/problem/1610/B
// check for both a[i] & a[n-1-i], remove both and check if palindromic [choose the minimum removal one]

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
    string input; 
    cin >> input;
    if (n==1) {
        cout << 0 << endl;
        return;
    }
    if (n==2) {
        if (input[0]==input[1]) cout << 0 << endl;
        else cout << 1 << endl;
        return;
    }
    char c1 = '#', c2 = '#';
    bool palindromic = true;
    for (int i=0; i<n/2; i++) {
        if (input[i] != input[n-1-i]) {
            c1 = input[i]; 
            c2 = input[n-1-i];
            palindromic = false;
            break;
        }
    }
    if (palindromic) {
        cout << 0 << endl;
        return;
    }
    // cout << c1 << " " << c2 << endl;
    // either drop c1 or c2 and check if palindromic - check which takes minimum
    int ans = INT_MAX;
    int i=0, j=n-1, cnt=0;
    bool isPalin = true;
    while (i<j) {
        if (input[i]!=input[j]) {
            if (input[i]==c1) {
                i++; cnt+=1;
                continue;
            }
            if (input[j]==c1) {
                j--; cnt+=1;
                continue;
            }
            isPalin = false;
            break;
        }
        else {
            i++; j--;
        }
    }
    if (isPalin) {
        ans = min(ans, cnt);
    }
    i=0, j=n-1, cnt=0;
    isPalin = true;
    while (i<j) {
        if (input[i]!=input[j]) {
            if (input[i]==c2) {
                i++; cnt+=1;
                continue;
            }
            if (input[j]==c2) {
                j--; cnt+=1;
                continue;
            }
            isPalin = false;
            break;
        }
        else {
            i++; j--;
        }
    }
    if (isPalin) {
        ans = min(ans, cnt);
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    
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