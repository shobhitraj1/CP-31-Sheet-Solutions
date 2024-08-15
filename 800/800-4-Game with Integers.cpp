// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1899/A

#include <bits/stdc++.h>
using namespace std;

// a_3k   --> Vanya Not win - Vova can do exact opposite of what Vanya does
// a_3k+1 --> Vanya Win - Vanya does -1
// a_3k+2 --> Vanya Win - Vanya does +1

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        if (n%3==0) cout << "Second" << endl;
        else cout << "First" << endl;
    }

    return 0;
}