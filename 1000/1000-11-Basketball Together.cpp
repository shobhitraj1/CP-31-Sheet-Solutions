// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1725/B

#include <bits/stdc++.h>
using namespace std;

// just keep forming the team with maximum power member and see how many teams can be formed

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
    int n, power;
    cin >> n >> power;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    sort(all(array));
    // print(array);

    int count = 0;
    for (int i=n-1; i>=0; i--) {
        int p = ceil(power, array[i]);
        if (p*array[i] == power) p+=1;
        if (p<=n) {
            count+=1;
            n-=p;
        }
        else if (p>n) break;
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

    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}