// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1794/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Can increase a_i by 1 if factor of a_(i+1) & check if its not divisible by a_(i-1)
// Or just start from right and do this, so don't have to check 
// This approach gives TLE

// Optimised approach -->
// If a_i is divides a_(i+1), (a_(i+1))+1 will never by divisible by a_i until it's 1
// So, first make all 1's 2, then do this operation from left, this will make sure atmost 2n operations

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
            if (array[i]==1) array[i]=2; // making 1's 2
        }    
        // int count = 0; 
        // int tempcount = 0;
        // for (int i=n-1; i>0; i--) {
        //     tempcount = 0;
        //     while (array[i]%array[i-1]==0) {
        //         array[i-1] += 1;
        //         count+=1;
        //         tempcount+=1;
        //         if (count > 2*n) {
        //             // array[i-1] -= tempcount;
        //             // count -= tempcount;
        //             // for (int j=i; j<n; j++) {
        //             //     array[j] += 1;
        //             //     count+=1;
        //             // }
        //             array[i] += 1;
        //             array[i-1] -= tempcount;
        //             count -= tempcount;
        //             if (i+1<n) i+=1; // else last element, so changing it doesn't effect
        //         }
        //     }
        // }   

        for (int i=0; i<n-1; i++) {
            if (array[i+1]%array[i]==0) array[i+1]+=1;
        }

        for (int i=0; i<n; i++) {
            cout << array[i] << " ";
        }   
        cout << endl;
    }
    
    return 0;
}