// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1671/C

#include <bits/stdc++.h>
using namespace std;

// iterating on days gave TLE, instead iterate on items
// sort the prices, and cnt for each item, how many days will it be bought

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
    int n, x;
    cin >> n >> x;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    sort(all(array));
    // print(array);
    int days = 0, cur = 0;
    for (int i=0; i<n; i++) {
        cur += array[i];
        if (cur>x) break;
        // cur + (days-1)*(i+1) <= x
        days += ((x-cur)/(i+1)+1);
    }
    cout << days << endl;

    // for (int i=1; i<=n; i++) {
    //     array[i] += array[i-1];
    // }
    // // print(array);
    // int day = 0;
    // int sugarPackets = 0;
    // while (true) {
    //     // cout << "hi" << endl;
    //     // bitwise shift operator >> has lower precedence than the + - operators
    //     int low = 1;
    //     int high = n;
    //     while (high-low>1) {
    //         int mid = low + ((high-low)>>1); 
    //         if (array[mid] + day*(mid) <= x) low = mid;
    //         else high = mid-1;
    //     }
    //     int packs = 0;
    //     if (array[high] + day*(high) <= x) packs = high;
    //     else if (array[low] + day*(low) <= x) packs = low;
    //     else packs = 0;
    //     // cout << packs << endl;
    //     if (packs == 0) break;
    //     sugarPackets += packs;
    //     day += 1;
    // }
    // cout << sugarPackets << endl;
    
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