// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1703/E

#include <bits/stdc++.h>
using namespace std;

// first and last letter of all the 4 strings of the boundary being considored should be same
// Change the rest to make minimum change possible and all are same

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
        cout << el << endl;
    }
    cout << endl;
}

vector<string> convertVerticalGrid (vector<string>& grid) {
    vector<string> ans;
    int n = grid.size();
    for (int i=0; i<n; i++) {
        string temp = "";
        for (int j=0; j<n; j++) {
            temp.push_back(grid[j][i]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int strDiff(const string& s1, const string& s2, const string& s3, const string& s4) {
    int n = s1.length(), changes = 0;
    for (int i = 1; i < n - 1; ++i) {
        int count0 = (s1[i] != '0') + (s2[i] != '0') + (s3[i] != '0') + (s4[i] != '0');
        int count1 = (s1[i] != '1') + (s2[i] != '1') + (s3[i] != '1') + (s4[i] != '1');
        changes += min(count0, count1);
    }
    return changes;
}

int countMinChange (string& s1, string& s2, string& s3, string& s4) {
    // minimum changes to make to make all strings same

    int ans = strDiff(s1,s2,s3,s4);
    // cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;

    // first and last letter of all strings should be same, either 0 or 1
    int count0 = (s1[0] != '0') + (s2[0] != '0') + (s3[0] != '0') + (s4[0] != '0');
    int count1 = (s1[0] != '1') + (s2[0] != '1') + (s3[0] != '1') + (s4[0] != '1');
    ans += min(count0, count1);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i=0; i<n; i++) {
        cin >> grid[i];
    }   
    vector <string> verGrid = convertVerticalGrid(grid);
    // print(grid);
    // print(verGrid);
    int count = 0;
    for (int i=0; i<n/2; i++) {
        string str1 = grid[i];
        str1 = str1.substr(i,n-2*i); 
        string str2 = verGrid[n-1-i];
        str2 = str2.substr(i,n-2*i);
        string str3 = grid[n-1-i];
        reverse(all(str3));
        str3 = str3.substr(i,n-2*i);
        string str4 = verGrid[i];
        reverse(all(str4));
        str4 = str4.substr(i,n-2*i);
        // cout << str1 << " " << str2 << " " << str3 << " " << str4 << endl;
        count += countMinChange(str1,str2,str3,str4);
        // cout << count << endl;
    }
    cout << count << endl;
    
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