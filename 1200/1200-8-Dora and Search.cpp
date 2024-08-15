// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1793/C

#include <bits/stdc++.h>
using namespace std;

/*
Suppose we want to check whether the entire array satisfies the claim. 
If this is the case, then we can output the entire array as an answer. 
Otherwise, one of the two extreme elements does not meet our requirements. 
From this we can conclude that all segments containing an element that does not meet our requirements 
will also be incorrect, because this extreme element will remain the minimum/maximum.
2 pointers l & r, initially 1 & n, if maximum and minimum, l++ or r-- accordingly
O(n) --> if considor the fact that array is permutation, in the start, mini = 1 & maxi = n,
if encounter l=mini (l++, mini++), l=maxi (l++, maxi--), r=mini(r--, mini++), r=maxi(r--, maxi--)
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> array(n);
    multiset<int> ms;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        ms.insert(array[i]);
    }   
    if (n<=3) {
        cout << -1 << endl;
        return;
    }
    int i=0, j=n-1;
    int mini = *min_element(all(array));
    int maxi = *max_element(all(array));
    while (i<j) { //j-i>3
        if (array[i]!=mini && array[i]!=maxi && array[j]!=mini && array[j]!=maxi) {
            cout << i+1 << " " << j+1 << endl;
            return;
        }
        if (array[i]==mini || array[i]==maxi) {
            ms.erase(ms.find(array[i]));
            i++;
        }
        else {
            ms.erase(ms.find(array[j]));
            j--;
        }
        mini = *ms.begin();
        maxi = *(--ms.end());
    }
    cout << -1 << endl;
    
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