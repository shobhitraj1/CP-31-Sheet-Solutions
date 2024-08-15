// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1666/D

#include <bits/stdc++.h>
using namespace std;
#define int long long

// brute force removal of extra letters & checking if result is equal to test string

signed main(){

    int t;
    cin >> t;
    while (t--){
        string input, test;
        cin >> input >> test;
        int inputLength = input.length();
        int testLength = test.length();
        int inputArray[26] = {0};
        int testArray[26] = {0};
        for (int i=0; i<inputLength; i++) {
            inputArray[input[i]-'A'] += 1;
        }
        for (int i=0; i<testLength; i++) {
            testArray[test[i]-'A'] += 1;
        }
        // for (int i=0; i<26; i++) {
        //     cout << inputArray[i] << " ";
        // }
        // cout << endl;
        // for (int i=0; i<26; i++) {
        //     cout << testArray[i] << " ";
        // }
        // cout << endl;
        // cout << endl;
        int removal[26] = {0};
        string output = "YES";
        for (int i=0; i<26; i++) {
            removal[i] = inputArray[i] - testArray[i];
            if (removal[i]<0) {
                output = "NO";
                break;
            }
        }
        if (output=="NO") cout << "NO" << endl;
        else {
            for (int i=0; i<inputLength; i++) {
                if (removal[input[i]-'A']>0) {
                    removal[input[i]-'A'] -= 1;
                    input[i] = '#';
                }
            }
            string ans = "";
            for (int i=0; i<inputLength; i++) {
                if (input[i]!='#') {
                    ans += input[i];
                }
            }
            if (ans==test) cout << "YES" << endl;
            else cout << "NO" << endl;

        }

    }
    
    return 0;
}