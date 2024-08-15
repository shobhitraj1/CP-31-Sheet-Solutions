// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1873/C

#include <bits/stdc++.h>
using namespace std;

// brute force counting 

int main(){

    int t;
    string input[10];
    cin >> t;
    while (t--){
        int score = 0;
        for (int i=0; i<10; i++) {
            cin >> input[i];
        }   
        for (int i=0; i<10; i++) {
            // first or last row - 1 point
            if (input[0][i] == 'X') score += 1;
            if (input[9][i] == 'X') score += 1;
            // 2nd or 9th row - 1/2 points
            if (input[1][i] == 'X') {
                if (i==0 or i==9) score += 1;
                else score += 2;
            }
            if (input[8][i] == 'X') {
                if (i==0 or i==9) score += 1;
                else score += 2;
            }
            // 3rd or 8th row - 1/2/3 points
            if (input[2][i] == 'X') {
                if (i==0 or i==9) score += 1;
                else if (i==1 or i==8) score += 2;
                else score += 3;
            }
            if (input[7][i] == 'X') {
                if (i==0 or i==9) score += 1;
                else if (i==1 or i==8) score += 2;
                else score += 3;
            }
            // 4th or 7th row - 1/2/3/4 points
            if (input[3][i] == 'X') {
                if (i==0 or i==9) score += 1;
                else if (i==1 or i==8) score += 2;
                else if (i==2 or i==7) score += 3;
                else score += 4;
            }
            if (input[6][i] == 'X') {
                if (i==0 or i==9) score += 1;
                else if (i==1 or i==8) score += 2;
                else if (i==2 or i==7) score += 3;
                else score += 4;
            }
            // 5th or 6th row - 1/2/3/4/5 points
            if (input[4][i] == 'X') {
                if (i==0 or i==9) score += 1;
                else if (i==1 or i==8) score += 2;
                else if (i==2 or i==7) score += 3;
                else if (i==3 or i==6) score += 4;
                else score += 5;
            }
            if (input[5][i] == 'X') {
                if (i==0 or i==9) score += 1;
                else if (i==1 or i==8) score += 2;
                else if (i==2 or i==7) score += 3;
                else if (i==3 or i==6) score += 4;
                else score += 5;
            }
        }  
        cout << score << endl;
    }
    
    return 0;
}