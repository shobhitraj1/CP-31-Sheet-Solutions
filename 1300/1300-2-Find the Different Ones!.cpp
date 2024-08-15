// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1927/D

#include <bits/stdc++.h>
using namespace std;

// store the indices of each element
// binary search among the indices which index is missing (that index doesn't have same element)

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
    // cout << endl;
}

template<typename K, typename V>
void print(const map<K, vector<V>> &m) {
    for (const auto &el : m) {
        cout << "{" << el.first << ": ";
        print(el.second);
        cout << "} " << endl;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> array(n+1);
    map <int, vector<int>> mp;
    for (int i=1; i<=n; i++) {
        cin >> array[i];
        mp[array[i]].pb(i);
    }   
    // print(mp);
    int q, l, r;
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        int elem = array[l];
        if (array[r]!=elem) {
            cout << l << " " << r << endl;
            continue;
        }
        // cout << "crossed" << endl;
        // check if all indices from l to r in mp[elem]
        // vector<int> vec = mp[elem]; // this vec will always be sorted
        // print(vec); cout << endl;
        int first_idx = lower_bound(all(mp[elem]), l) - mp[elem].begin();
        int last_idx = lower_bound(all(mp[elem]), r) - mp[elem].begin();
        int low = first_idx;
        int high = last_idx;
        if (high - low == r - l) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        // cout << low << " " << high << " crossed" << endl;
        bool found = false;
        while (high-low>1) {
            int mid = (high+low)/2;
            // cout << "mid = " << mid << endl;
            if (array[mp[elem][mid]]!=elem) {
                found = true;
                cout << l << " " << mp[elem][mid] << endl;
                break;
            }
            int first_idx = lower_bound(all(mp[elem]), mp[elem][low]) - mp[elem].begin();
            int last_idx = lower_bound(all(mp[elem]), mp[elem][high]) - mp[elem].begin();
            int mid_idx = lower_bound(all(mp[elem]), mp[elem][mid]) - mp[elem].begin();
            // cout << first_idx << " " << mid_idx << " " << last_idx << endl;
            if (mid_idx - first_idx == mp[elem][mid]-mp[elem][low]) low = mid;
            else high = mid;
        }
        if (found) continue;
        int left = mp[elem][low], right = mp[elem][high];
        int mid = (left+right)/2;
        if (array[mid]!=elem) cout << l << " " << mid << endl;
        else cout << -1 << " " << -1 << endl; // will never reach

    }
    
}

// ALTERNATE SOLUTION - From Official Tutorial
/*
Before processing the requests, let's calculate the position p_i of the nearest element to the left that is not equal to it (we will consider p1=−1). 
To do this in linear time, we will traverse the array from left to right. For the i-th element (1<i≤n), 
if ai≠ai−1, then pi=i−1, otherwise pi=pi−1 (all elements between pi−1 and i will be equal to ai by construction).
To answer a query, we will fix the right boundary as one of the positions for the answer. Then the best of all suitable positions for it is p_r, as it is the maximum, 
and we just need to check that l≤p_r. (Note that by fixing any other position, you may not find the answer for a segment of the form [1,1,1,…,1,2])
*/

void solve1() {
    int n;
    cin >> n;
    vector<int> array(n+1);
    vector<int> pref(n+1);
    for (int i=1; i<=n; i++) {
        cin >> array[i];
    }   
    pref[0] = pref[1] = -1;
    for (int i=2; i<=n; i++) {
        if (array[i]==array[i-1]) pref[i]=pref[i-1];
        else pref[i] = i-1;
    }
    int q, l, r;
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        if (pref[r]<l) cout << -1 << " " << -1 << endl; // checking if the last unequal element is before l or with range
        else cout << pref[r] << " " << r << endl;
    }
    
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