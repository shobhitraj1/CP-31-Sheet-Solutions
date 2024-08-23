// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1837/D

#include <bits/stdc++.h>
using namespace std;

// if bracket not regular --> -1
// if bracket is regular & not beautiful (either front regular or reverse regular) --> then coloured in one color
// else if bracket is regular & beautiful, then exist another regular in reverse order --> 2 colors

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

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
    vector<int> array(n);
    int cnt = 0, color = 1;
    for (int i=0; i<n; i++) {
        if (input[i]=='(') {
            array[i] = (cnt>=0) ? 1 : 2;
            cnt++;
        }
        else {
            array[i] = (cnt>0) ? 1 : 2;
            cnt--;
        }
    }
    if (cnt) cout << -1 << endl;
    else {
        int color = 0;
        for (int i=0; i<n; i++) {
            if (array[i]==1) color++;
        }
        if (color == 0 || color == n) {
            cout << 1 << endl;
            for (int i=0; i<n; i++) {
                cout << 1 << " ";
            }
            cout << endl;
        } 
        else {
            cout << 2 << endl;
            print(array);
        }
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