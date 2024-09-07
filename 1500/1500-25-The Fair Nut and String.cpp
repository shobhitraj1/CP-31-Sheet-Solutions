// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1084/C

#include <bits/stdc++.h>
using namespace std;

//       123456789 => indices
// Eg. - abaabaaba => Here, Sequences possible are [1,3,6,9], [1,6,9], [1,3,9], [3,9], etc.
// If a's are separated by b, then they can be included in the sequence
// And in the group of a's any one of them or none of them could be included (cnt+1 possiblities)
// Therefore, total permutations by product rule, -1 in end for the permutation where none of the 'a' is selected

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    string input;
    cin >> input;
    input = "b" + input;
    input.pb('b');
    int n = input.length();
    int ans = 1;
    int cntA = 0;
    for (int i=0; i<n; i++) {
        if (input[i]=='b') {
            ans = (ans*(cntA+1))%MOD;
            cntA = 0;
        }
        if (input[i]=='a') cntA++;
    }
    cout << ans-1 << endl; 
    
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}