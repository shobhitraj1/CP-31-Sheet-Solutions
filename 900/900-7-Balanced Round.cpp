// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1850/D

#include <bits/stdc++.h>
using namespace std;

// Convert to success array when elements difference <= k
// count the largest sequence of 1 occuring in success array

int main(){
    int t, n, k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        int array[n];
        int success[n-1] = {0};
        for (int i=0; i<n; i++){
            cin >> array[i];
        }
        sort(array, array + n);
        for (int i=1; i<n; i++){
            if (array[i] - array[i-1] <= k){
                success[i-1]=1;
            }
        }
        // for (int i=0; i<n-1;i++){
        //     cout << success[i] << " ";
        // }
        // cout << endl;

        // count the largest sequence of 1 occuring in success array
        int max = 0;
        int a = 0;
        for (int i=0; i<n-1;i++){
            if (success[i]==1){
                a+=1;
            }
            else {
                if (max < a) max = a;
                a = 0;
            }
        }
        if (max < a) max = a;
        cout << n - (max+1) << endl;
               
    }

    return 0;
}