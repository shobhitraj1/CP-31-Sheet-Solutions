// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1873/E

#include <bits/stdc++.h>
using namespace std;

// The order of the corals doesn't matter, just the height
// h < minHeight => water = 0
// minHeight < h < maxheight = use binary search
// h > maxHeight => water = n*maxHeight - sum

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

template<typename T1, typename T2>
void print(const vector<pair<T1, T2>> &v) {
    for (const auto &el : v) {
        cout << "(" << el.first << ", " << el.second << ") ";
    }
    cout << endl;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> array(n);
    int sum = 0;
    // int minHeight = INF;
    // int maxHeight = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        // sumArray[i] = array[i]; not here, prefix sum of sorted array
        sum+=array[i];
        // minHeight = min(array[i],minHeight);
        // maxHeight = max(array[i],maxHeight);
    }   

    sort(all(array));
    int minHeight = array[0];
    int maxHeight = array[n-1];
    
    // min height = min. coral height (h = minHeight) => water = 0
    // max height = max. coral height (h = maxHeight) => water = n*maxHeight - sum 
    if (x>=n*maxHeight-sum) {  // h>= maxHeight
        x-=(n*maxHeight-sum);
        int m = x/n;
        int h = maxHeight + m;
        cout << h << endl;
    }
    else {
        // h = minHeight
        vector<int> sumArray(n);
        sumArray[0] = array[0];
        for (int i=1; i<n; i++) {
            sumArray[i] = array[i];
            sumArray[i] += sumArray[i-1];
        }

        // binary search b/t minHeight & maxHeight
        int low = minHeight;
        int high = maxHeight;

        while (low<=high) {

            int mid = low + (high - low) / 2;

            // find index of mid in array & then check if water till there is x or not

            // Get an iterator pointing to the first element that is not less than the target
            auto it = lower_bound(array.begin(), array.end(), mid);

            // // If the iterator points to the beginning and the first element is greater than the target
            // if (it == array.begin() && *it > mid) {
            //     int h = -1; // Indicating no valid index found
            // }

            if (it == array.end() || *it > mid) {
                --it;
            }

            // Return the index of that element
            int index = distance(array.begin(), it);

            if (mid*(index+1) - sumArray[index] <= x) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        cout << high << endl;
        












        // vector<int> uptill(n); --> gives TLE
        // for (int i=0; i<n; i++) {
        //     uptill[i] = array[i]*(i+1) - sumArray[i];
        // }

        // // Get an iterator pointing to the first element that is greater than the x
        // auto it = upper_bound(uptill.begin(), uptill.end(), x);

        // // Otherwise, move the iterator one step back to get the largest element <= target
        // --it;
        // // Return the index of that element
        // int index = distance(uptill.begin(), it);
        // int h = array[index];
        // print(array);
        // print(sumArray);

        // try to apply binary search here also
        // for (h; h<array[index+1]; h++) { 
        //     if (h*(index+1)-sumArray[index] > x) {
        //         break;
        //     }
        // }
        // cout << h-1 << endl;

        // vector<int> ans(array[index+1]-array[index]+1); --> gives MLE
        // for (int i=0; i<ans.size(); i++) {
        //     ans[i]=h+i;
        //     ans[i]*=(index+1);
        //     ans[i]-=sumArray[index];
        // }

        // // Get an iterator pointing to the first element that is greater than the x
        // it = upper_bound(ans.begin(), ans.end(), x);

        // // Otherwise, move the iterator one step back to get the largest element <= target
        // --it;
        // // Return the index of that element
        // int i = distance(ans.begin(), it);
        // h = h+i;
        // cout << h << endl;

        
 
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