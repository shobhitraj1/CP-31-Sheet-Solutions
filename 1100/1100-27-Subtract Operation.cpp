// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1656/B

#include <bits/stdc++.h>
using namespace std;

/*
Note that, after deleting element a_j, all numbers in the set are of the form a_i−a_j, since the previous substractions are cancelled. 
Therefore, the final element will be the difference between the last element and the previous element which was erased. 
So we just need to check if k is the difference of two elements in the set, which can be done by sorting and using the double pointer technique in O(nlogn) time.
Lets say array is --> a_i, a_j, a_k, a_l
Subtract a_i --> a_j-a_i, a_k-a_i, a_l-a_i
Subtract a_j-a_i --> a_k-a_j, a_l-a_j
Subtract a_k-a_j --> a_l-a_j-(a_k-a_j)=a_l-a_k (in the end, needs to be difference of 2 numbers)
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n, k, input;
    cin >> n >> k;
    set <int> st;
    bool found = false;
    for (int i=0; i<n; i++) {
        cin >> input;
        if (st.count(k+input)) found = true;
        if (st.count(input-k)) found = true;
        st.insert(input);
    }   
    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;
        
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}