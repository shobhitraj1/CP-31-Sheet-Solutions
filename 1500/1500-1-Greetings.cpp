// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1915/F

#include <bits/stdc++.h>
using namespace std;

// Greetings will be done when a person crosses other
// Hence, problem reduces to counting inversions

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int merge(vector<int>& arr, int left, int mid, int right){
    int count = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } 
        // right is smaller
        else {
            arr[k] = R[j];
            count += (n1-i);
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
    return count;
}

int mergeSort(vector<int>& arr, int l, int r){
    int count = 0;
    if (l>=r) return count;
    int mid = l + (r-l)/2;
    count += mergeSort(arr,l,mid);
    count += mergeSort(arr,mid+1,r);
    count += merge(arr,l,mid,r);
    return count;
}

void solve() {
    int n, s, e;
    cin >> n;
    vector<pair<int, int>> res;
    for (int i=0; i<n; i++) {
        cin >> s >> e;
        res.emplace_back(s, e);
    }   
    sort(all(res));
    vector<int> array;
    for (int i=0; i<n; i++) {
        array.pb(res[i].second);
    }
    int ans = mergeSort(array, 0, n-1);
    cout << ans << endl;
    
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