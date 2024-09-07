// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1332/C

#include <bits/stdc++.h>
using namespace std;

// Each individual word of length k has to be equal and palindrome, minimum changes required to achieve this
// For each index < k/2, calculate the minimum changes for it & its mirror to becomes equal in all the n words
// When k = odd, the middle alphabet has to be equal too (it will be palindromic automatically), so add the minimum changes for that

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

int minChange(vector<string>& words, int index) {
    int n = words.size();
    int len = words[0].length();
    vector<int> pref(26, 0), suf(26, 0);
    for (int i=0; i<n; i++) {
        pref[words[i][index]-'a']++;
        suf[words[i][len-1-index]-'a']++;
    }
    int mini = INF;
    for (int i=0; i<26; i++) {
        mini = min(mini, 2*n-(pref[i]+suf[i]));
    }
    return mini;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string input;
    cin >> input;
    // each word has to be equal and palindrome
    vector<string> words;
    int len = k;
    for (int i=0; i<n; i++) {
        string word = input.substr(i, len);
        words.pb(word);
        i += (len-1);
    }
    // print(words);
    int changes = 0;
    for (int i=0; i<len/2; i++) {
        changes += minChange(words, i);
    }
    int mini = minChange(words, len/2);
    if (len&1) changes += (mini/2);
    cout << changes << endl;
    
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