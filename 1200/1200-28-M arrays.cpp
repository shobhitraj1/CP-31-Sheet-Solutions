// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1497/B

#include <bits/stdc++.h>
using namespace std;

// Assign numbers to sets 0 to m-1
// cnt+=1 for numbers in 0, can be all grouped together (if exists)
// if (m%2==0) and numbers are there in m%2 --> cnt+=1
// for i = 1 to m/2 [group i and m-i numbers such that]
// Eg. - if (m==8) and in group 1 = 1,1,1,1, group 7 = 7,7
// 1 7 1 7 1 can be a group, cnt+=1
// leftover will be max(i,m-i) - (min(i,m-i)+1), if (leftover>0) cnt+=leftover

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
    int n, m;
    cin >> n >> m;
    vector<int> array(n);
    vector<int> div(m, 0);
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        div[array[i]%m]++;
    }   
    // print(div);
    if (div[0]) cnt += 1;
    for (int i=1; i<=m/2; i++) {
        // cout << "i = " << i << ", cnt = " << cnt << endl;
        if (i == m-i) {
            if (div[i]>0) cnt += 1;
            break;
        }
        int ans = min(div[i], div[m-i]);
        if (ans == 0) {
            cnt += max(div[i], div[m-i]);
            continue;
        }
        cnt += 1;
        div[i]-=(ans+1); div[m-i]-=(ans+1);
        if (div[i]>0) cnt += div[i];
        if (div[m-i]>0) cnt += div[m-i];
    }
    cout << cnt << endl;

    
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