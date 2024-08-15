// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1606/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Whichever's more can only be more by 1, as one leads to another, so
// if ab>ba, it starts with "ab" & ends with "ab/abbb...", make the last "b" as "a"
// As if ab --> aa (reduce 1 ab) or else abbb...bbb --> abbb...bba (add 1 ba)
// if ab<ba, it starts with "ba" & ends with "ba/baaa...", make the last "a" as "b"
// As if ba --> bb (reduce 1 ba) or else baaa...aaa --> baaa...aab (add 1 ab)
// So, have to make only one change all the time, which is the minimum

signed main(){

    int t;
    cin >> t;
    while (t--){
        string input;
        cin >> input;
        int n = input.length();
        int ab = 0, ba = 0, a = 0, b = 0;
        if (input[0]=='a') a+=1;
        else b+=1;
        for (int i=1; i<n; i++) {
            if (input[i]=='a') a+=1;
            else b+=1;
            if (input[i]=='a' && input[i-1]=='b') ba+=1;
            else if (input[i]=='b' && input[i-1]=='a') ab+=1;
        }  
        if (ba==ab) cout << input << endl;
        else {
            if (ab>ba) {
                // if (ab==1 && a>b) {
                //     input[n-1]='a';
                // }
                // else if (ab==1 && b>=a) {
                //     input[0]='b';
                // }
                // else {
                //     for (int i=1; i<n; i++) {
                //         if (input[i]=='b' && input[i-1]=='a') {
                //             input[i-1] = 'b';
                //             break;
                //         }
                //     } 
                // }
                input[n-1] = 'a';
            }
            else {
                // if (ba==1 && b>a) {
                //     input[n-1]='b';
                // }
                // else if (ba==1 && a>=b) {
                //     input[0]='a';
                // }
                // else {
                //     for (int i=1; i<n; i++) {
                //         if (input[i]=='a' && input[i-1]=='b') {
                //             input[i-1] = 'a';
                //             break;
                //         }
                //     } 
                // }
                input[n-1] = 'b';
            }
            cout << input << endl;
        }   

    }

    return 0;
}