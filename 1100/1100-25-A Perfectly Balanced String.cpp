// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1673/B

#include <bits/stdc++.h>
using namespace std;

/*
The string is perfectly balanced if it is periodic and the repeating pattern contains all distinct alphabets.
Let the number of distinct characters in s be k and length of s be n. 
Then, s will be perfectly balanced if and only if si,si+1,…,si+k−1 are all pairwise distinct for every i in the range 1≤i≤n−k+1.
Proof -->
If k distinct characters, then in every k size substring, if no of distinct chars is less than k,
then some character is bound to repeat by Pigeonhole Principle, hence in that substring, 
some character appears twice, and one character doesn't appear, so 2-0 = 2, not perfect.
*/

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
    string input;
    cin >> input;
    int n = input.length();
    vector<int> alpha(26, 0);
    for (int i=0; i<n; i++) {
        alpha[input[i]-'a']++;
    }
    int count = 0; // no of distinct characters (can be highest 26)
    for (int i=0; i<26; i++) {
        if (alpha[i]) count+=1;
    }
    bool perfect = true;
    for (int i=0; i<=n-count; i++) {
        unordered_set<char> st;
        for (int j=0; j<count; j++) { // j = 0 to count-1
            st.insert(input[i+j]);
        }
        if (st.size() != count) perfect = false;
    }
    if (perfect) cout << "YES" << endl;
    else cout << "NO" << endl;    

    
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