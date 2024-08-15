// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1849/B

#include <bits/stdc++.h>
using namespace std;

// first only keep the remainders & if rem=0, replace it with k
// then decreasing order of the elements, their index is the answer
// 1st way to sort - make vector pair <value, index> (use stable_sort)
// 2nd way (more optimized in terms of memory) - sort only index based on values of array[index-1]'s

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n);

    // // Creating a vector of pairs (value, index)
    // vector<pair<int, int>> result;

    // Creating a vector of indices
    vector<int> indices(n);

    for (int i=0; i<n; i++) {
        cin >> array[i];
        array[i] %= k;
        if (array[i]==0) array[i]=k;
        // result.emplace_back(array[i], i + 1); // (value, 1-based index)
        indices[i] = i + 1; // 1-based index
    }   
   
    // // Sort the pairs in decreasing order of the values
    // stable_sort(result.begin(), result.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    //     return a.first > b.first;
    // });

    // // Extract the indices from the sorted pairs
    // for (const auto& pair : result) {
    //     cout << pair.second << " ";
    // }

    // Sort the indices based on the corresponding values in array
    stable_sort(indices.begin(), indices.end(), [&array](int a, int b) {
        return array[a - 1] > array[b - 1]; // 1-based to 0-based index
    });

    for (int i=0; i<n; i++) {
        cout << indices[i] << " ";
    }
    cout << endl;   
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}