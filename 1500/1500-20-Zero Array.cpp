// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1201/B

#include <bits/stdc++.h>
using namespace std;

// Greedily, first keep removing the smallest element, and subtract from the current largest
// For subtracting from the largest, use the optimization such that the largest doesn't go below second largest
// i.e. don't insert 2 elements in the multiset in one iteration, insert only one and remove 2

/* 
Alternate Solution :-
There are 2 things needed to be possible to make all elements zero:
1: The sum of the elements must be even.
2: The biggest element have to be less or equal than the sum of all the other elements.
If both are true, the answer is "YES", otherwise "NO".
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n, input;
    cin >> n;
    multiset<int> ms;
    for (int i=0; i<n; i++) {
        cin >> input;
        ms.insert(input);
    } 
    while (ms.size()>2) {
        int mini = *ms.begin();
        int maxi = *(--ms.end());
        int maxi2 = *(--(--ms.end()));
        ms.erase(--ms.end());
        ms.erase(ms.begin());
        if (maxi == mini) {
            if (ms.size()&1 && maxi&1) cout << "NO" << endl;
            else cout << "YES" << endl;
            return;
        }
        if (mini <= maxi-maxi2) ms.insert(maxi-mini);
        else {
            int x = maxi-maxi2;
            maxi = maxi2;
            mini -= x;
            ms.erase(ms.find(maxi2));
            maxi2 -= (mini/2);
            ms.insert(maxi2);
            if (mini&1) maxi2--;
            ms.insert(maxi2);
        }
    }
    if (ms.size()==1) cout << "NO" << endl;
    else if (ms.size()==2 && *ms.begin() != *(--ms.end())) cout << "NO" << endl; 
    else cout << "YES" << endl;
    
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