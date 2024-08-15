// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1832/C

#include <bits/stdc++.h>
using namespace std;

// Can remove element if abs diff with prev + abs diff with next = abs diff of prev & next
// So, no difference to contrast (as contrast depends on adjacent elements only)

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
    int contrast = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (i>0) contrast += abs(array[i]-array[i-1]);
    }   
    // cout << contrast << endl;
    if (contrast==0) {
        cout << 1 << endl;
        return;
    }
    int cnt = 0;
    int i=1, j=0;
    while (i+1<n) {
        if (abs(array[i]-array[j])+abs(array[i+1]-array[i]) == abs(array[i+1]-array[j])) {
            cnt += 1;
            i+=1;
        }
        else {
            j=i;
            i+=1;
        }
    }
    cout << n-cnt << endl;

    
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