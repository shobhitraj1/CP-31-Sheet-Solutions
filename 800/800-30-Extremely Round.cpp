// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1766/A

#include <bits/stdc++.h>
using namespace std;

// No of digits in n :-
// 1 - n = 0 + floor(n/1)
// 2 - 9 + floor(n/10)
// 3 - 18 + floor(n/100)
// 4 - 27 + floor(n/1000)
// 5 - 36 + floor(n/10000)
// 6 - 45 + floor(n/100000)

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        // Convert integer to string
        string numStr = to_string(n);
        int numDigits = numStr.length();
        int x = 9*(numDigits-1) + n/pow(10,numDigits-1);
        cout << x << endl;
    }
    
    return 0;
}