// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1536/B

#include <bits/stdc++.h>
using namespace std;

// Maximum length of MEX can be <= 3, as 3*26*26 > 1000(n)
// So, check all substrings upto length 3

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

bool isSubstring(string& str, string& substr) {
    return search(str.begin(), str.end(), substr.begin(), substr.end()) != str.end();
}

void solve() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    // for (char c='a'; c<='z'; c++) {
    //     string sub(1, c);
    //     if (!isSubstring(input, sub)) {
    //         cout << sub << endl;
    //         return;
    //     }
    // }

    // for (char c1='a'; c1<='z'; c1++) {
    //     for (char c2='a'; c2<='z'; c2++) {
    //         string sub = {c1, c2};
    //         if (!isSubstring(input, sub)) {
    //             cout << sub << endl;
    //             return;
    //         }
    //     }
    // }

    // for (char c1='a'; c1<='z'; c1++) {
    //     for (char c2='a'; c2<='z'; c2++) {
    //         for (char c3='a'; c3<='z'; c3++) {
    //             string sub = {c1, c2, c3};
    //             if (!isSubstring(input, sub)) {
    //                 cout << sub << endl;
    //                 return;
    //             }
    //         }
    //     }
    // }
    string sub = "a";
    bool found = isSubstring(input, sub);
    while(found) {
        int m = sub.length();
        if (sub[m-1]-'a'<25) sub[m-1] = (char)(sub[m-1]+1);
        else {
            sub[m-1] = 'a';
            if (m==1) sub = "a"+sub;
            else {
                if (sub[m-2]-'a'<25) sub[m-2] = (char)(sub[m-2]+1);
                else {
                    sub[m-2] = 'a';
                    if (m==2) sub = "a"+sub;
                    else {
                        if (sub[m-3]-'a'<25) sub[m-3] = (char)(sub[m-3]+1);
                    }
                }
            }
        }
        found = isSubstring(input, sub);
    }
    cout << sub << endl;

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