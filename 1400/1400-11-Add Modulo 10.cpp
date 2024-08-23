// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1714/E

#include <bits/stdc++.h>
using namespace std;

// if last digit is 0, it can't be increased further
// if last digit is 2, the pattern repeats i.e. it again becomes 2 after incrementing 20
// So, make every number's last digit 2, and then take the maximum element in the array
// And check if every number can be made equal to the maximum by adding multiple of 20

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int makeDigit2[] = {0, 1, 0, 9, 18, 5, 6, 25, 14, 23};

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    int maxi = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        array[i] += makeDigit2[array[i]%10];
        maxi = max(maxi, array[i]);
    }   
    bool possible = true;
    for (int i=0; i<n; i++) {
        if (array[i]!=maxi) {
            if (array[i]%10==0) possible = false;
            else {
                if ((maxi-array[i])%20!=0) possible = false;
            }
        }
    }
    if (possible) cout << "Yes" << endl;
    else cout << "No" << endl;

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