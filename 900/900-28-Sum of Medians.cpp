// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1440/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// sum of median of all n groups of k elements, same result in the sorted order
// As always want same no. of elements on the left of the median that are smaller
// & same no. of elements on the right of the median that are greater

signed main(){

    int t, n, k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        int arr[n*k];
        for (int i=0; i<n*k; i++) {
            cin >> arr[i];
        }   
        int a;
        if (n%2==0) {
            a = n-n/2;
        }
        else a = n-n/2-1;
        int sum = 0;
        // cout << "a = " << a << endl;
        int count = 0;
        for (int i = n*k-1-a; i>=0; i-=(a+1)){
            // cout << arr[i] << " ";
            sum+=arr[i];
            count+=1;
            if (count == k) break;
        }
        // cout << endl;
        cout << sum << endl;

    }
    
    return 0;
}