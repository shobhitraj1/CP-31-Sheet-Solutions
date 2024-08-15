// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1679/B

#include <bits/stdc++.h>
using namespace std;

// When type 1, change that index & store the changes indices in a set
// When type 2, sum = n*newElem (and keep track of newElem)

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

template<typename T>
void print(const vector<T> &v) {
    for (const auto &el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> array(n);
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        sum += array[i];
    }   
    bool allSame = false;
    int sameElem = 0;
    unordered_set<int> indicesChanged;
    for (int i=0; i<q; i++) {
        int type, index, newElem;
        cin >> type;
        if (type == 1) cin >> index >> newElem;
        else cin >> newElem;
        if (type == 1) {
            if (sameElem) {
                if (indicesChanged.count(index-1)) {
                    sum = sum - array[index-1] + newElem;
                    array[index-1] = newElem;
                    cout << sum << endl;
                }
                else {
                    sum = sum - sameElem + newElem;
                    array[index-1] = newElem;
                    indicesChanged.insert(index-1);
                    cout << sum << endl;
                }
            }
            else {
                sum = sum - array[index-1] + newElem;
                array[index-1] = newElem;
                cout << sum << endl;
            }
        }
        else {
            sum = n*newElem;
            allSame = true;
            sameElem = newElem;
            indicesChanged.clear();
            cout << sum << endl;
        }

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
    // cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}