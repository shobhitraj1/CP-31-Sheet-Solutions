// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1692/E

#include <bits/stdc++.h>
using namespace std;

/*
Compute prefix sums on the array, so we can find out the value of al+⋯+ar quickly. 
Let's iterate through the left endpoint l from 1 to n. 
Afterwards, we can binary search on the smallest value of r such that al+⋯+ar=s, since this sum is strictly increasing.
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
    int n, s;
    cin >> n >> s;
    vector<int> array(n);
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        sum += array[i];
    }     
    if (sum<s) cout << -1 << endl;
    else if (sum==s) cout << 0 << endl;
    else {
        int m = sum-s;
        // remove m 1's with least possible moves, see both sides
        // remove a 1's from left & b 1's from right such that a+b = min & minimum moves
        vector<int> left(m+1);
        vector<bool> left1(m+1, true);
        vector<int> right(m+1);
        vector<bool> right1(m+1, true);
        left[0]=0; right[m]=0; left1[0] = false; right1[m] = false;
        int tempsum = 0;
        for (int i=0; i<n; i++) {
            tempsum+=array[i];
            if (tempsum>m) break;
            // cout << tempsum << " " << left1[tempsum] <<endl;
            if (left1[tempsum]) {
                left[tempsum]=i+1;
                left1[tempsum]=false;
            } 
        }
        tempsum = 0;
        for (int i=0; i<n; i++) {
            tempsum+=array[n-1-i];
            if (tempsum>m) break; 
            // cout << tempsum << " " << right1[m-tempsum] <<endl;
            if (right1[m-tempsum]) {
                right[m-tempsum]=i+1;
                right1[m-tempsum]=false;
            }       
        }
        int min = n;
        // print(left);
        // print(right); 
        for (int i=0; i<=m; i++) {
            if (min>left[i]+right[i]) min = left[i]+right[i];
        }
        cout << min << endl;
    }

    
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