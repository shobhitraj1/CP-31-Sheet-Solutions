// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1901/A

#include <bits/stdc++.h>
using namespace std;

// refueling the car
// 0 - a1 - a2 - a3 - ... - an - x
// Hence, dist = a1-0, a2-a1, ..., an-a(n-1), 2(x-an) --> select max of this as
// have to travel these dist without refueling

int main(){

    int t, n, x;
    cin >> t;
    while (t--){
        cin >> n >> x;
        int array[n];
        for (int i=0; i<n; i++){
            cin >> array[i];            
        }
        int max = array[0];
        for (int k=1; k<n; k++){
            if (max < array[k] - array[k-1]){
                max = array[k] - array[k-1];
            }
        }
        int last = 2*(x - array[n-1]);
        if (max < last) max = last;
        cout << max << endl;
    }

    return 0;
}