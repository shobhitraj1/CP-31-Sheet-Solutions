// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1931/E

#include <bits/stdc++.h>
using namespace std;

// Anna will try to remove zeroes from the end of the numbers by reversing
// All digits of a number except the last zeroes will be added to the end number for sure
// So, Anna will try to remove zeroes and Sasha will try to save them (both will greedily choose numbers with highest no. of zeroes)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

pair<int, int> dig(int input) {
    int zeroes = 0;
    int num = input;
    while (num%10 == 0) {
        num/=10;
        zeroes+=1;
    }
    int tot = (int)(log10(input)+1);
    return {tot-zeroes,zeroes};
}

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

void solve() {
    int n, m, input;
    cin >> n >> m;
    vector<pair<int, int>> res;
    for (int i=0; i<n; i++) {
        cin >> input;
        res.emplace_back(dig(input));
    }   
    sort(all(res), comp); 
    // print(res);  
    int digits = 0; 
    for (int i=n-1; i>=0; i-=2) {
        digits += res[i].first;
        if (i>0) digits += (res[i-1].first + res[i-1].second);
    }
    if (digits>m) cout << "Sasha" << endl;
    else cout << "Anna" << endl;

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