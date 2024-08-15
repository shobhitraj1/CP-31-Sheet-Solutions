// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1119/B

#include <bits/stdc++.h>
using namespace std;

// Binary Search on how many bottles can be placed - predicate function
// Sort the heights of the first k bottles which are to be placed
// Place the bottles in pair in decreasing order of their height & check if they can be arranged in fridge

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

bool canPlace (vector<int>& array, int bottles, int height) {
    vector<int> fridge(array.begin(),array.begin()+bottles);
    sort(all(fridge));
    for (int i=bottles-1; i>=0; i--) {
        int maxht = fridge[i];
        if (i-1>=0) {
            maxht = max(maxht, fridge[i-1]);
            i--;
        }
        if (maxht>height) return false;
        else height-=maxht;
    }
    return true;

}

void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    if (array[0]>h) {
        cout << 0 << endl;
        return;
    }
    // T T T T F F F F --> find last true
    int low = 1;
    int high = n;
    while (high-low>1) {
        int mid = (low+high)/2;
        if (canPlace(array, mid, h)) low = mid;
        else high = mid-1;
    }
    if (canPlace(array, high, h)) cout << high << endl;
    else if (canPlace(array, low, h)) cout << low << endl;
    
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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}