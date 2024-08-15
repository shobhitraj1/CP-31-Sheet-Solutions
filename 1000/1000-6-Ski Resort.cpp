// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1840/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

// convert array to 1's when can go skiing that day
// count the no of >=k consecutive days

// if consecutive count >= k --> 
// possible with k days = (count-k+1)
// possible with k+1 days = (count-(k+1)+1) ... & so on
// possible with count days = (count-(count)+1) = 1
// So, add 1+2+...+(count-k+1)

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, k, temp;
    cin >> n >> k >> temp;
    int array[n];
    int days = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (array[i]<=temp) {
            days+=1;
            array[i] = 1;
        }
        else array[i] = 0;
    }   
    // for (int i=0; i<n; i++) {
    //     cout << array[i] << " ";
    // }
    // cout << endl;
    int count = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (array[i]==1) count+=1;
        else {
            if (count>=k) {
                int m = count-k+1;
                ans += (((m+1)*m)/2);
            }
            count = 0;
        }
    }
    if (count>=k) {
        int m = count-k+1;
        ans += (((m+1)*m)/2);
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}