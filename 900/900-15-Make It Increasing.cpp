// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1675/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Start from right & keep dividing a_i by 2 if >= a_(i+1) & 
// check any element reaches 0 or 1, then their left element is smaller
// The above approach gives TLE

// One way can be to check 
// if a_i {after dividing by 2 to make it less than a_(i+1)} < i , then -1
// If a_i is 0, and its not the first element, then -1

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

signed main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        bool input = true;
        for (int i=0; i<n; i++) {
            cin >> array[i];
            if (i!=0 && array[i]==0) input = false;
        }  
        if (!input) cout << -1 << endl;
        else {
            if (n==1) cout << 0 << endl;
            else {
                // int count = 0;
                // int i = n-2;
                // bool flag = true;
                // while (i>=0 && flag) {
                //     while(array[i]>=array[i+1]) {
                //         array[i] /= 2;
                //         count+=1;
                //         if (array[i]==0 && i>0) {
                //             count = -1;
                //             flag = false;
                //             break;
                //         }
                //     }
                //     i--;
                // }
                // cout << count << endl;
                int count = 0;
                for (int i=n-2; i>=0; i--) {
                    if (array[i]>=array[i+1]){   
                        int f = log2(ceil(array[i],array[i+1]));
                        int q = pow(2, f);
                        if (array[i]/q>array[i+1]) f+=1; // taking ceil of log_2(a[i]/a[i+1])
                        array[i] /= pow(2,f);
                        count+=f;
                        // cout << "f = " << f <<", count = " << count << endl;
                        if (array[i] == array[i+1]) {
                            array[i]/=2;
                            count+=1;
                        }
                        // cout << "f = " << f <<", count = " << count << endl;
                        // int m = log2(array[i]);
                        // int p = pow(2, m);
                        // if (p<array[i]) m+=1; // taking ceil of log_2(a[i])
                        if (i>array[i]) {
                            count = -1;
                            break;
                        }
                    }
                }
                cout << count << endl;
            }
        }
    }
    
    return 0;
}