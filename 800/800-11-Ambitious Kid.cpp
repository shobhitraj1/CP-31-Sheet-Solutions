// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1866/A

#include <bits/stdc++.h>
using namespace std;

// element with smallest absolute value - make it zero in least steps

int main(){

    int n;
    cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    int min = abs(array[0]);
    for (int i=1; i<n; i++) {
        if (abs(array[i])<min){
            min = abs(array[i]);
        }
    }
    cout << min << endl;

    return 0;
}