// Created by Shobhit Raj
// Problem link - https://codeforces.com/problemset/problem/1904/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// (x,y) + (±a,±b)/(±b,±a) = both king's and queen's position
// So, total 8 possibilities - remove the duplicate possibilities

signed main(){

    int t, a, b, x_k, y_k, x_q, y_q;
    cin >> t;
    while (t--){
        cin >> a >> b >> x_k >> y_k >> x_q >> y_q;
        // cout << a <<" "<< b <<" "<< x_k <<" "<< y_k <<" "<< x_q <<" "<< y_q;
        // cout << a << endl;
        // cout << b << endl;
        pair<int, int> king(x_k, y_k);
        pair<int, int> queen(x_q, y_q);
        vector<pair<int, int>> kings;   
        vector<pair<int, int>> queens;  
        pair<int, int> move1(a, b);
        pair<int, int> move2(a, -b);
        // pair<int, int> move3(-a, b);
        // pair<int, int> move4(-a, -b);
        pair<int, int> move5(b, a);
        pair<int, int> move6(b, -a);
        // pair<int, int> move7(-b, a);
        // pair<int, int> move8(-b, -a);
        vector<pair<int, int>> moves;  
        moves.push_back(move1);
        moves.push_back(move2);
        // moves.push_back(move3);
        // moves.push_back(move4);
        moves.push_back(move5);
        moves.push_back(move6);
        // moves.push_back(move7);
        // moves.push_back(move8);
        // Print the vector of pairs
        // std::cout << "Vector of pairs:" << std::endl;
        // for (const auto& pair : moves) {
        //     cout << "H : ";
        //     std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
        // }
        for (int i=0; i<4; i++){
            std::pair<int, int> sumPair;
            sumPair.first = king.first + moves[i].first;
            sumPair.second = king.second + moves[i].second;
            std::pair<int, int> diffPair;
            diffPair.first = king.first - moves[i].first;
            diffPair.second = king.second - moves[i].second;
            kings.push_back(sumPair);
            kings.push_back(diffPair);
            sumPair.first = queen.first + moves[i].first;
            sumPair.second = queen.second + moves[i].second;
            diffPair.first = queen.first - moves[i].first;
            diffPair.second = queen.second - moves[i].second;
            queens.push_back(sumPair);
            queens.push_back(diffPair);
        }
        // std::cout << "Kings Vector of pairs:" << std::endl;
        // for (const auto& pair : kings) {
        //     cout << "H : ";
        //     std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
        // }
        // std::cout << "Queens Vector of pairs:" << std::endl;
        // for (const auto& pair : queens) {
        //     cout << "H : ";
        //     std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
        // }

        // Use a set to store unique pairs
        set<pair<int, int>> uniquePairs1(kings.begin(), kings.end());
        set<pair<int, int>> uniquePairs2(queens.begin(), queens.end());

        // Convert the set back to a vector
        vector<pair<int, int>> uniqueVec1(uniquePairs1.begin(), uniquePairs1.end());
        vector<pair<int, int>> uniqueVec2(uniquePairs2.begin(), uniquePairs2.end());

        int count = 0;
        for (int i=0; i<uniqueVec1.size(); i++){
            for (int j=0; j<uniqueVec2.size(); j++){
                if ((uniqueVec1[i].first == uniqueVec2[j].first) && (uniqueVec1[i].second == uniqueVec2[j].second)) count+=1;
            }
        }  
        cout << count << endl;

    }
    
    return 0;
}