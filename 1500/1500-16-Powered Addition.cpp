// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1338/A

#include <bits/stdc++.h>
using namespace std;

// As, any indices can be increased by 2^t-1, increase all that are less than any previous elements
// For each element, calculate the maximum element to its left and calculate how much it has to be increased (this will be the ans)
// All other increases will be covered within this ans 

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }  
    int maxi = LLONG_MIN; 
    for (int i=1; i<n; i++) {
        if (array[i] < array[i-1]) {
            maxi = max(maxi, array[i-1]-array[i]);
        }
        array[i] = max(array[i], array[i-1]);
    }
    int add = 1;
    int time = 0;
    while (maxi>0) {
        maxi -= add;
        add*=2;
        time++;
    }
    cout << time << endl;

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