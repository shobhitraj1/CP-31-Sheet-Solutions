// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1691/B

#include <bits/stdc++.h>
using namespace std;

// Shoes has to be shuffled such that student gets shoes >= his size
// But that largest size can be only replaces by itself, once done that
// 2nd largest size can be replaced by itself, and so on...
// So, if every element in the array occurs atleast twice, its possible

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
    string output = "YES";
    int count = 1;
    for (int i=1; i<n; i++) {
        if (array[i]==array[i-1]) count+=1;
        else {
            if (count<2) {
                output = "NO";
                break;
            }
            else count = 1;
        }
    }
    if (count<2) output = "NO";
    if (output == "NO") cout << -1 << endl;
    else {
        // just shuffle the same elements

        vector <int> result;
        int count = 1;
        for (int i=1; i<n; i++) {
            if (array[i]==array[i-1]) count+=1;
            else {
                if (count%2==0) {
                    int j = i-count;
                    for (int k=j; k<i; k+=2) {
                        result.pb(k+2); // 1-based indexing
                        result.pb(k+1); // 1-based indexing
                    }
                }
                else {
                    int j = i - count;
                    for (int k=j; k<i-3; k+=2) {
                        result.pb(k+2); // 1-based indexing
                        result.pb(k+1); // 1-based indexing
                    }
                    result.pb(i);
                    result.pb(i-2);
                    result.pb(i-1);
                }
                count = 1;
            }
        }
        if (count%2==0) { // for the last element
            int j = n-count;
            for (int k=j; k<n; k+=2) {
                result.pb(k+2);
                result.pb(k+1);
            }
        }
        else {
            int j = n - count;
            for (int k=j; k<n-3; k+=2) {
                result.pb(k+2); // 1-based indexing
                result.pb(k+1); // 1-based indexing
            }
            result.pb(n);
            result.pb(n-2);
            result.pb(n-1);
        }
        print(result);
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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}