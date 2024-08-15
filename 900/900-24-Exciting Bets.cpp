// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1543/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// If 2 numbers are separated by x, then their gcd will be always <= x
// Therefore, max. gcd possible is their difference, minimize the moves to reach there

// if a==b -> infinite -> 0 0 

signed main(){

    int t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (a>b) swap(a,b);
        if (a==b) cout << 0 << " " << 0 << endl;
        else if (a==0) cout << b << " " << 0 << endl;
        else if (a==1) {
            if (b>2) cout << b-1 << " " << 1 << endl;
            else cout << 1 << " " << 0 << endl;
        } 
        else { // One possible way is making a zero which takes a moves
            int maxgcd = b-a;
            int m = a%maxgcd;
            // cout << "m = " << m << endl;
            int A = m; // either I subtract m from both a & b to make gcd = maxgcd
            int B = maxgcd-m; // or I add maxgcd-m to both a & n to make gcd = maxgcd
            // This way make a to nearest multiple of maxgcd < or > a;
            // Other ways will require more than a moves
            int ans = a;
            if ((b-A)%maxgcd==0 && A<ans) ans = A;
            if ((b+B)%maxgcd==0 && B<ans) ans = B;

            cout << maxgcd << " " << ans << endl;
        }
        

    }
    
    return 0;
}