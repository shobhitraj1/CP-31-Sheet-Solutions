// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1780/B

#include <bits/stdc++.h>
using namespace std;

// biggest pairwise gcd b/t prefix (no. included) and suffix (no. excluded)

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
    vector<int> prefix(n);
    vector<int> suffix(n);
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        sum += array[i];
    }   
    // biggest pairwise gcd b/t prefix (no. included) and suffix (no. excluded)
    int temp = 0;
    int maxi = 0;
    for (int i=0; i<n; i++) {
        temp+=array[i];
        prefix[i]=temp;
        suffix[i]=sum-temp;
        if (temp>0 && sum-temp>0) maxi = max(maxi,__gcd(temp,sum-temp));
    }
    // print(prefix);
    // print(suffix);
    cout << maxi << endl;


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