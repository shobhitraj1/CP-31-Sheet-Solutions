// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1859/B

#include <bits/stdc++.h>
using namespace std;

// Max. beauty can be when transfer all the mins. to one array, 
// take min of that array (which will be min of mins) & add to 2nd min of remaining arrays

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
    int n, m;
    cin >> n;
    vector<pair<int, int>> res;
    int N = n;
    int beauty = 0;
    int lowest = INF;
    int total2ndMin = 0;
    while (N--) {
        cin >> m;
        vector<int> array(m);
        for (int i=0; i<m; i++) {
            cin >> array[i];
        } 
        int min1 = min(array[0],array[1]);
        int min2 = max(array[0],array[1]);
        for (int i=2; i<m; i++) {
            if (array[i]<=min1) {
                min2 = min1;
                min1 = array[i];
            }
            else if (array[i]<min2) min2 = array[i];
        }
        res.emplace_back(min1,min2);
        beauty += min1;
        total2ndMin += min2;
        if (lowest > min1) lowest = min1;
    }  

    if (n==1) cout << beauty << endl;
    else {
        int result = 0;
        // for (const auto& pair : res) {
        //     std::cout << "Min: " << pair.first << ", 2nd Min: " << pair.second << std::endl;
        // }
        // cout << endl;
        for (const auto& pair : res) {
            if (total2ndMin-pair.second+lowest > result) result = total2ndMin-pair.second+lowest;
        }
        cout << result << endl;

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

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}