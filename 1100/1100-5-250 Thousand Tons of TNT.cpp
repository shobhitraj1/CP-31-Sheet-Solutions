// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1899/B

#include <bits/stdc++.h>
using namespace std;

// Precompute divisors (possible K's for each n) & then check for each K 
// Max. no. of divisors => cbrt(n)
// O(n) for finding each max-min => Hence, cbrt(n) * n for each testcase

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;
const int N = 2e5;

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

vector <int> divisors[N];

void solve() {
    int n, tempSum;
    cin >> n;
    vector<int> array(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> array[i];
        array[i] += array[i-1]; // prefix sum
    }   
    int ans = 0;
    // print(array);
    for (auto& k: divisors[n]) {
        int mini = INF, maxi = 0;
        for (int i=k; i<=n; i+=k) {
            tempSum = array[i] - array[i-k];
            // cout << "K = " << k << " = "<< tempSum << endl;
            mini = min(mini, tempSum);
            maxi = max(maxi, tempSum);
        }
        ans = max(ans, maxi-mini);
    }
    cout << ans << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    for (int i=1; i<N; i++) {
        for (int j=i; j<N; j+=i) {
            divisors[j].push_back(i);
        }
    }

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}