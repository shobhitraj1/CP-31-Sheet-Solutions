// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1631/B

#include <bits/stdc++.h>
using namespace std;

// Every element has to made the last element 
// Accordingly traverse from back & check if not, then make operation
// And make total current count elements to the left the last desired element

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

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    // 2*current has to be <= n
    int current = 0;
    int count = 0;
    int elem = array[n-1];
    for (int i=n-1; i>=0; i--) {
        // cout << i << " " << current << endl;
        if (array[i]==elem) {
            current+=1;
        }
        else {
            i-=current;
            count+=1;
            current+=current;
            i+=1; // to nullify decrement of for loop
        }
    }
    cout << count << endl;
    

    
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