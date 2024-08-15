// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1881/D

#include <bits/stdc++.h>
using namespace std;

/*
To solve the problem, we need to decompose all numbers in the array into prime divisors. 
After that, let's calculate the number of each divisor, summarizing the decompositions of all numbers.
If each divisor enters k⋅n times, where k is a natural number, then we can equalize all the numbers in the array: 
we will sequentially apply the operation so that each number consists of the same set of prime divisors.
If some divisor enters a different number of times (not a multiple of n), then it will not be possible to equalize the numbers in the array.
*/

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

const int N = 1e6+10;
vector<bool> isPrime(N,true);
vector<int> lp(N,0), hp(N,0);
// vector <int> divisors[N];

void solve() {
    int n, input, num;
    cin >> n;
    map <int, int> mp;
    // for (int i=0; i<n; i++) {
    //     cin >> input;
    //     while (input!=1) {
    //         mp[divisors[input][0]]++;
    //         input /= divisors[input][0];
    //     }
    // }   
    for (int i=0; i<n; i++) {
        cin >> num;
        while (num>1){ // O(logN)
            int pF = lp[num];
            while (num%pF==0){
                num/=pF;
                mp[pF]++;
            }
        }
    }
    for (auto& elem : mp) {
        if (elem.second%n) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    //     freopen("output.txt","w",stderr);
    // #endif

    // // Divisors - O(NlogN)
    // for (int i=2; i<N; i++) {
    //     for (int j=i; j<N; j+=i) {
    //         divisors[j].push_back(i);
    //     }
    // }

    isPrime[0] = false;
    isPrime[1] = false;

    // O(N*log(logN)) - Sieve algorithm
    for (int i=2; i<N; i++) {
        if (isPrime[i]) {
            hp[i]=lp[i]=i; // as loop starting 2*i
            for (int j=2*i; j<N; j+=i) {
                isPrime[j] = false;
                hp[j]=i;
                if (lp[j]==0) lp[j]=i;
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}