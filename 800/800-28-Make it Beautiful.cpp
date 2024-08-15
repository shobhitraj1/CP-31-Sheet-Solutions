// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1783/A

#include <bits/stdc++.h>
using namespace std;

// To make beautiful - can just sort in decreasing order
// decreasing order will only be ugly if the max element appears everytime
// i.e. all the elements of the array are same
// but decreasing order if the first 2 elements are same then ugly, 
// so after checking that all the elements are not same, can just swap 
// 2nd and last element

int main(){

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        int array[n];
        int count = 0;
        for (int i=0; i<n; i++) {
            cin >> array[i];
        } 
        // Sort the array in decreasing order using std::sort with a lambda function
        sort(array, array + n, [](int a, int b) {
            return a > b; // Sort in decreasing order
        });

        // // Sort the array in decreasing order using std::sort with std::greater
        // sort(array, array + n, std::greater<int>());
    
        int element = array[0];
        for (int i=0; i<n; i++){
            if (array[i] == element) count += 1;
        }
        if (count == n) cout << "NO" << endl;
        else {
            // swapping 2nd and last element
            int a = array[1];
            array[1] = array[n-1];
            array[n-1] = a;
            cout << "YES" << endl;
            for (int i=0; i<n; i++) {
                cout << array[i] << " ";
            } 
            cout << endl;
        }  


    }
    
    return 0;
}