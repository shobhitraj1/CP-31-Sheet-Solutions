// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1791/E

#include <bits/stdc++.h>
using namespace std;

// 1. If even number of negative --> all can be made positive => max sum = All summation
// 2. If odd number of negative --> Least element should be made negative => max sum accordingly
// Keep count of zero too and adjust accordingly - zero will be automatically taken care of in min
// Similar to question --> 1000-24-Numbers Box (https://codeforces.com/problemset/problem/1447/B)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    int minElem = INF;
    int sum = 0;
    int negative = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (array[i]<0) negative+=1;
        minElem = min(abs(array[i]),minElem);
        sum += abs(array[i]); 
    }   

    if (negative%2!=0) sum-=(2*minElem);
    cout << sum << endl;

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