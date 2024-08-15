// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1610/B

#include <bits/stdc++.h>
using namespace std;

// If deleting some occurances of x makes palindromic, deleting all occurances will also be palindromic
// the first time, difference occurs, either of the 2 has to be removed or else removing other elements will never make palindrome
// check for both a[i] & a[n-1-i], remove both and check if palindromic

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
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    if (n<=2) {
        cout << "YES" << endl;
        return;
    }
    int num1 = -1, num2 = -1;
    bool palindromic = true;
    for (int i=0; i<n/2; i++) {
        if (array[i] != array[n-1-i]) {
            num1 = array[i]; 
            num2 = array[n-1-i];
            palindromic = false;
            break;
        }
    }
    if (palindromic) {
        cout << "YES" << endl;
        return;
    }
    // cout << num1 << " " << num2 << endl;
    // either drop num1 or num2 and check if palindromic
    int i=0, j=n-1;
    bool isPalin = true;
    while (i<j) {
        if (array[i]==num1) {
            i++;
            continue;
        }
        if (array[j]==num1) {
            j--;
            continue;
        }
        if (array[i]!=array[j]) {
            isPalin = false;
            break;
        }
        else {
            i++; j--;
        }
    }
    if (isPalin) {
        cout << "YES" << endl;
        return;
    }
    i=0, j=n-1;
    isPalin = true;
    while (i<j) {
        if (array[i]==num2) {
            i++;
            continue;
        }
        if (array[j]==num2) {
            j--;
            continue;
        }
        if (array[i]!=array[j]) {
            isPalin = false;
            break;
        }
        else {
            i++; j--;
        }
    }
    if (isPalin) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;


    
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