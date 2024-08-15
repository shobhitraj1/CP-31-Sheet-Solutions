// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1794/C

#include <bits/stdc++.h>
using namespace std;

// as the elements are sorted, we will definitely include the rightmost element
// after each addition of element, we will include it, the choice to remove the leftmost of the subsequence or just add additional
// maxi*array[right]/(curCnt+1) OR maxi*array[right]/array[left] (and curCnt remains same)
// Make choice based on this if greater than or even equal to (in order to maximize the length)

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
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }   
    vector<int> ans(n, 1);
    int curCnt = 0, left = 0, right = 0;
    int maxi = 1;
    for (int i=0; i<n; i++) {
        if (array[left]>=(curCnt+1)) {
            maxi*=array[right];
            right++;
            curCnt++;
        }
        else {
            maxi/=array[left];
            maxi*=array[right];
            left++; right++;
        }
        ans[i] = curCnt;
    }
    print(ans);

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