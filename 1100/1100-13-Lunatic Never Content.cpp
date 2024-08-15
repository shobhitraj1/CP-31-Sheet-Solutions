// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1826/B

#include <bits/stdc++.h>
using namespace std;

// If already palindromic, then infinite x --> output 0
// If not, then max x possible is maxElem (if 0 is palindrome to maxElem)
// min x is 1
// Brute force will give TLE 
// max possible x for i and n-1-i will be abs(array[i]-array[n-1-i])
// HCF of all these pairwise difference will give the ans

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

bool isPalindromic (vector<int> &array) {
    int n = array.size();
    for (int i=0; i<n/2; i++) {
        if (array[i]!=array[n-1-i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   

    if(isPalindromic(array)) {
        cout << 0 << endl;
        return;
    }

    int hcf = 0;
    for (int i=0; i<n/2; i++) {
        hcf = __gcd(hcf,abs(array[i]-array[n-1-i]));
    }
    // if (hcf==0) hcf+=1; // because if still 0, then already palindromic, 
    // should have been caught in the start only
    cout << hcf << endl;
    
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