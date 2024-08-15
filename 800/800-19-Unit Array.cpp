// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1834/A

#include <bits/stdc++.h>
using namespace std;

// a = -1's
// b = 1's
// b >= a & a = even --> '0'
// b >= a & a = odd --> '1'
// a > b => dif = ceil[(a-b)/2] and a_new = a - dif 
// Now, if a_new = even --> dif, else a_new = odd --> dif + 1

int main(){

    int t, n, input;
    cin >> t;
    while (t--){
        cin >> n;
        int a = 0;
        int b = 0;
        for (int i=0; i<n; i++){
            cin >> input;  
            if (input == -1) a+=1;    
            if (input == 1) b+=1;    
        }
        if (b>=a){
            if (a%2==0) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else {
            int dif = (a-b);
            if (dif%2==0) dif/=2;
            else dif=dif/2 + 1;
            a = a - dif;
            if (a%2==0) cout << dif << endl;
            else cout << dif+1 << endl;

        }

    }

    return 0;
}