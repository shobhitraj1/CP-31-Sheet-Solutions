// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1872/E

#include <bits/stdc++.h>
using namespace std;

// As XOR is commutative, associative and cyclic (i.e. a^b = c, then b^c = a & c^a = b)
// Also, a^a = 0 & a^0 = a
// When type 1 operation is done :-
// Every "1" element is changed to "0", so is removed from xorr1 & added to xorr0
// Every "0" element is changed to "1", so is added to xorr1 & removed from xorr0
// Adding can simply be done by xorring of the segment to the xorr (can be computed using prefix xor array as associative)
// Removing can also be done by xorring of the segment as it would nullify the already present elements as a^a = 0

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
    vector<int> pref(n+1, 0);
    for (int i=0; i<n; i++) {
        cin >> array[i];
        pref[i+1] = pref[i]^array[i];
    }   
    string input;
    cin >> input;
    int xorr0 = 0, xorr1 = 0;
    for (int i=0; i<n; i++) {
        if (input[i]=='0') xorr0^=array[i];
        else xorr1^=array[i];
    }
    int q, type, l, r, num;
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> l >> r;
            int newXor = pref[r]^pref[l-1];
            xorr0^=newXor;
            xorr1^=newXor;
        }
        else {
            cin >> num;
            if (num) cout << xorr1 << " ";
            else cout << xorr0 << " ";
        }
    }
    cout << endl;
   
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