// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1374/C

#include <bits/stdc++.h>
using namespace std;

// just count ')' that doesn't have corresponding '(' before it

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
    string input; 
    cin >> input;
    int count = 0;
    int answer = 0;
    for (int i=0; i<n; i++) {
        if (input[i]=='(') count+=1;
        else {
            count-=1;
            if (count<-answer) answer+=1;
        }
    }
    cout << answer << endl;
    
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