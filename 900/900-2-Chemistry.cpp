// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1883/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Count the occurance of each letter, if odd, have to remove it
// and accordingly see if removing k can bring down to exactly one letter having odd count
// but have to remove optimally, remove lowest odd first like in 
// "abaac" n = 5, k = 3 --> Array before & after removing, so first remove 1's 
// 3 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 - not optimal
// 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 - optimal
// Hence, sort the array

// Incorrect above logic, so correcting it
// Another tough testcase that I can think of, 
// aaabbbcccddd, n = 12, k = 3 --> should give YES, but
// 3 3 3 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// 0 3 3 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 - wrong
// 2 2 2 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 - right
// Hence, just subtract 1 from each odd to make it even (until k==0 or 26 alphabets over)
// And then check for no of odd counts - Need not sort the array to in this method

signed main(){

    int t, n, k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        string input;
        cin >> input;
        int array[26] = {0}; // use array instead of map or something to optimize
        for (int i=0; i<n; i++) {
            array[input[i] - 'a'] += 1;
        }     
        // for (int i=0; i<26; i++) {
        //     cout << array[i] << " ";
        // }
        // cout << endl;
        sort(array, array + 26);

        for (int i=0; i<26; i++) {            
            if (k>0 && array[i]%2!=0) {
                // cout << "k = " << k << endl;
                // if (k>=array[i]) {
                //     // array[i] = 0;
                //     k -= array[i];
                //     array[i] = 0; // this line should be after k is updated or else -= 0
                // }
                // else {
                //     array[i] -= k;
                //     k = 0;
                // }
                array[i] -= 1;
                k -= 1;
            }
        } 
        // for (int i=0; i<26; i++) {
        //     cout << array[i] << " ";
        // }
        // cout << endl;

        // If k is left at this point, then no odd count is left in the array, 
        // so if k is even, can easily remove the even elements, 
        // if k is odd, then remove the even elements and 1 more element which 
        // can be in the middle to preserve the palindromic sequence

        int count = 0;
        for (int i=0; i<26; i++) {
            if (array[i]%2!=0) count+=1;
        }
        if (count>1) cout << "NO" << endl;
        else cout << "YES" << endl;

        

    }
    
    return 0;
}