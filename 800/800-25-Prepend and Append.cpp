// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1791/C

#include <bits/stdc++.h>
using namespace std;

// brute force counting & checking where the pattern stops

int main(){

    int t, n;
    string input;
    cin >> t;
    while (t--){
        cin >> n;
        cin >> input;
        int array[n];
        for (int i=0; i<n; i++){
            array[i] = input[i] - '0'; // Convert character to integer
        }
        int i = 0;
        for (i; i<n/2; i++){
            if (array[i] == 0 && array[n-i-1] == 1){
                continue;
            }
            else if (array[i] == 1 && array[n-i-1] == 0){
                continue;
            }
            else {
                break;
            }
        }
        cout << n-(i*2) << endl;
    }

    return 0;
}