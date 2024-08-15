// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1704/B

#include <bits/stdc++.h>
using namespace std;

// just check if the entire sequence is in the range difference <= 2*x (max - min <= 2*x)

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
    int n, x;
    cin >> n >> x;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    int count = 0;
    int current = array[0];
    int min = array[0], max = array[0];
    for (int i=1; i<n; i++) {
        bool flag = true;
        if (abs(array[i]-current) <= 2*x) {
            if (array[i]>=current) {
                if (array[i]-min<=2*x) flag = false;
                if (array[i]>max) max = array[i];
            }
            else {
                if (max-array[i]<=2*x) flag = false;
                if (array[i]<min) min = array[i];
            }
        }
        if (flag) {
            count+=1;
            current = array[i];
            min = array[i];
            max = array[i];
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