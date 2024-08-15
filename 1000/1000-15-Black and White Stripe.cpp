// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1690/D

#include <bits/stdc++.h>
using namespace std;

// Since, want k consecutive letters segments, check all such segments, which has 
// minimum W's, there will be total n-k such segments
// Faster way to calculate W's in these segments would be prefix sum

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
    int n, k;
    cin >> n >> k;
    string input;
    cin >> input;

    // Brute Force Approach :- gives TLE
    // vector<int> cons;
    // int countB = 0;
    // int countW = 0;
    // for (int i=0; i<n; i++) {
    //     if (input[i]=='B') {
    //         countB+=1;
    //         if (i-1>=0 && input[i-1]=='W' && cons.size()==0) cons.pb(0); // to make first entry always black
    //         if (i-1>=0 && input[i-1]=='W') cons.pb(countW);
    //         countW=0;
    //     }
    //     else {
    //         countW+=1;
    //         if (i-1>=0 && input[i-1]=='B') cons.pb(countB);
    //         countB=0;
    //     }
    // }   
    // if (input[n-1] == 'B') {
    //     cons.pb(countB);
    //     cons.pb(k+1); // to make last entry always white
    // }
    // if (cons.size()==0) cons.pb(0);
    // if (input[n-1] == 'W') cons.pb(k+1); // to give infinite whites
    // int current = 0;
    // int whiteChange = 0;
    // int min = 200001;
    // // print(cons);
 
    // for (int i=0; i<cons.size(); i+=2) {
    //     current = 0;
    //     whiteChange = 0;
    //     for (int j=i; j<cons.size(); j+=2) {
    //         if (current > k) break;
    //         current+=cons[j];
    //         if (current > k) break;
    //         if (j+1<cons.size()) {
    //             if (current+cons[j+1]>k) {
    //                 whiteChange += (k-current); // modifying current so above below statement
    //                 current += (k-current);
    //                 break;
    //             }
    //             current += cons[j+1];
    //             whiteChange += cons[j+1];
    //         }
    //     }
    //     if (current >= k && whiteChange<min) min = whiteChange;
    // }
    // cout << min << endl;

    // Optimised Approach :-
    vector <int> WCount(n+1, 0);
    for (int i=1; i<=n; i++) { // made equal to n for (n+1) entries in WCount
        if (input[i-1]=='W') WCount[i]=WCount[i-1]+1;
        else WCount[i]=WCount[i-1];
    }

    // for (int i = 1; i <= n; i++) // better way of writing this
    //     WCount[i] = WCount[i - 1] + int(s[i - 1] == 'W');

    // print(WCount);
    int min = n+1;
    for (int i=k; i<=n; i++) {
        if (WCount[i]-WCount[i-k] < min) min = WCount[i] - WCount[i-k];
    }

    // for (int i = k; i <= n; i++) // better way of writing this
    //     result = min(result, w[i] - w[i - k]);

    cout << min << endl;


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