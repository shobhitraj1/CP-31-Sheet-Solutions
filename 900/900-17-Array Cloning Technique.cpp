// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1665/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Find out mode's frequency, have to make an array of that mode
// if f==n, then 0
// else ops += (1+f) operations, if 2f>=n, then output ops
// or continue ops += (1+2f) operations, if 4f>=n, then output ops & so on...
// increasing by power of 2

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }     
        int n = sizeof(array) / sizeof(array[0]);
        sort(array, array+n); // method of finding mode's freq requires sorting
        int count = 1;
        int maxFreq = 0;
        for (int i=1; i<n; i++){
            if (array[i]==array[i-1]) count+=1;
            else {
                if (count>maxFreq) maxFreq = count;
                count = 1;
            }
        }
        // cout << maxFreq << endl;
        if (count>maxFreq) maxFreq = count;
        if (maxFreq==n) cout << 0 << endl;
        else {
            int steps = 0;
            int i=1;
            while (pow(2,i)*maxFreq<=n) {
                steps+=1; //cloning
                steps+=pow(2,i-1)*maxFreq; //swapping (all the elements of the mode swapped)
                i+=1;
            }
            if (i==1){
                steps+=1;
                steps+=(n-maxFreq);
            }
            else if (n-pow(2,i-1)*maxFreq>0) {
                steps+=1; //last clone out of which some elements will be swapped, not all
                steps+=(n - pow(2,i-1)*maxFreq); //swapping (but only swap until necessary)
            }
            cout << steps << endl;
        }

    }
    
    return 0;
}