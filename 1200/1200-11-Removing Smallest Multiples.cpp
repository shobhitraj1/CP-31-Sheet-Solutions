// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1734/C

#include <bits/stdc++.h>
using namespace std;

// Start with dropping multiples of 1, 2, 3, ...n
// If encounter element that doesn't have to be dropped, break as smallest multiple dropped
// Else drop the element and mark it dropped, so don't count again when some other element's multiple 
// Time Complexity - O(nlogn) - Sieve of Eratosthenes

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    // reverse sieve of eratosthenes
    int ans = 0;
    for (int i=1; i<=n; i+=1) {
        for (int j=i; j<=n; j+=i) {
            if (input[j-1]=='0') {
                input[j-1]='2'; // already dropped, no longer in S
                ans += i;
            }
            else if (input[j-1]=='2') continue;
            else break;
        }
    }
    cout << ans << endl;

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