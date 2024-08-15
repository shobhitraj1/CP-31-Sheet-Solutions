// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1744/C

#include <bits/stdc++.h>
using namespace std;

// just maintain all the possible current color's index - curColor
// maintain all the possible green's index - green (add one more after rotating i.e. firstGreen + n)
// for each element in curColor, find the smallest element in green >= curColor
// (will always exist as largest element in green is >n), do binary search
// So, total time complexity --> |currentColor|*log(|green+1|)
// find the maximum difference of that (smallest element - cur element)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n;
    char current;
    cin >> n >> current;
    string input;
    cin >> input;

    if (current == 'g') cout << 0 << endl;
    else {
        vector <int> curColor;
        vector <int> green;
        int min = INF;
        for (int i=0; i<n; i++) {
            if (input[i]==current) curColor.pb(i+1);
            else if (input[i]=='g') {
                if (i+1<min) min = i+1;
                green.pb(i+1);
            }
        }
        green.pb(min+n);
        int max = 0;
        for (int i=0; i<curColor.size(); i++) {
            // binary search in green for smallest element i.e. >= curColor[i]
            // Use lower_bound to find the smallest element >= target
            // lower_bound leverages binary search --> So O(logn)
            auto it = lower_bound(green.begin(), green.end(), curColor[i]);
            int elem = *it;
            if (elem-curColor[i]>max) max = elem-curColor[i];
        }
        cout << max << endl;

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