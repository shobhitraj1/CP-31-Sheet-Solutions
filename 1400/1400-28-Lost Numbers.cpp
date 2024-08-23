// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1167/B
// My first interactive problem !!!

#include <bits/stdc++.h>
using namespace std;

// As the inter pair product all these numbers are unique, with 2 queries having 1 common element, can find 3 elements

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
    int a, b, c, d;
    std::map<int, std::pair<int, int>> mp = {
        {32, {4, 8}}, {60, {4, 15}}, {64, {4, 16}}, {92, {4, 23}}, {168, {4, 42}}, 
        {120, {8, 15}}, {128, {8, 16}}, {184, {8, 23}}, {336, {8, 42}},
        {240, {15, 16}}, {345, {15, 23}}, {630, {15, 42}},
        {368, {16, 23}}, {672, {16, 42}},
        {966, {23, 42}}
    };

    // queries
    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> a;
    cout << "? 1 3" << endl;
    fflush(stdout);
    cin >> b;
    cout << "? 4 5" << endl;
    fflush(stdout);
    cin >> c;
    cout << "? 4 6" << endl;
    fflush(stdout);
    cin >> d;

    vector<int> array(6);
    auto p1 = mp[a], p2 = mp[b];
    if (p2.first == p1.first) {
        array[0] = p1.first;
        array[1] = p1.second;
        array[2] = p2.second;
    }
    else if (p2.first == p1.second) {
        array[0] = p1.second;
        array[1] = p1.first;
        array[2] = p2.second;
    }
    else if (p2.second == p1.first) {
        array[0] = p1.first;
        array[1] = p1.second;
        array[2] = p2.first;
    }
    else if (p2.second == p1.second) {
        array[0] = p1.second;
        array[1] = p1.first;
        array[2] = p2.first;
    }
    auto p3 = mp[c], p4 = mp[d];
    if (p4.first == p3.first) {
        array[3] = p3.first;
        array[4] = p3.second;
        array[5] = p4.second;
    }
    else if (p4.first == p3.second) {
        array[3] = p3.second;
        array[4] = p3.first;
        array[5] = p4.second;
    }
    else if (p4.second == p3.first) {
        array[3] = p3.first;
        array[4] = p3.second;
        array[5] = p4.first;
    }
    else if (p4.second == p3.second) {
        array[3] = p3.second;
        array[4] = p3.first;
        array[5] = p4.first;
    }
    cout << "! ";
    print(array);
    fflush(stdout);

}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}