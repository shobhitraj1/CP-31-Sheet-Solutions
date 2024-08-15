// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1729/D

#include <bits/stdc++.h>
using namespace std;

/*
First, we sort the friends in descending order of y_i−x_i. 
Now for each friend we know the amount of money he lacks, or vice versa, which he has in excess.
In order to maximize the number of days, it is most advantageous for friends to break into pairs. 
It is the number of groups that matters, not the number of people in the group, so adding a third person to the pair won't improve the answer in any way.
Use 2 pointers to form pairs.
*/

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

void solve() {
    int n, input;
    cin >> n;
    vector<int> X(n);
    vector<int> array;
    for (int i=0; i<n; i++) {
        cin >> X[i];
    }  
    for (int i=0; i<n; i++) {
        cin >> input;
        array.pb(input-X[i]);
    } 
    sort(all(array));
    // print(array);
    int i=0, j=n-1;
    int cnt = 0;
    while (i<j) {
        if (array[i]+array[j]>=0) {
            cnt++; i++; j--;
        }
        else i++;
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