// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1862/B

#include <bits/stdc++.h>
using namespace std;

// If in sequence b, there's a smaller element after some bigger element, 
// then there must be an element >= before that smaller element in a, else
// the sequence would have been non decreasing.
// So basically, add that bigger element to get a 
// maybe just equal to the smaller element

int main(){

    int t, n, input;
    cin >> t;
    while (t--){
        cin >> n;
        vector<int> myVector;
        for (int i=0; i<n; i++){
            cin >> input;
            myVector.push_back(input);
            if (i != 0) { // ADD while taking input only
                if (input < myVector[myVector.size()-2]) {
                    myVector.push_back(input);
                }
            }
        }

        // ADDING LATER GIVES TLE

        // // logic is faulty if totally decreasing, like 16 13 10 8
        // for (int i=1; i<n; i++){
        //     if (myVector[i] < myVector[i-1]){
        //         myVector.insert(myVector.begin() + i, myVector[i]);
        //         i++;
        //     }
        // }

        // because the array size is increasing and loop is running for constant n
        // it finishes after n iterations and doesn't consider after that - so 
        // replace it with size of the vector
        // for (int i=1; i<myVector.size(); i++){
        //     if (myVector[i] < myVector[i-1]){
        //         myVector.insert(myVector.begin() + i, myVector[i]);
        //         i++;
        //     }
        // }
        cout << myVector.size() << endl;
        for (int i=0; i<myVector.size(); i++){
            cout << myVector[i] << " ";
        }
        cout << endl;

    }

    return 0;
}