// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/fractional-knapsack_975286?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std ;

bool compare(pair<int,int>a , pair<int,int> b){
    double r1 = (double)a.second / a.first ;
    double r2 = (double)b.second / b.first ;
    return r1 > r2 ;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    double profit = 0.0 ;
    sort(items.begin(),items.end(),compare) ;
    for(int i=0 ; i<n ; i++){
        if(w-items[i].first >= 0){
            w -= items[i].first ;
            profit += items[i].second ;
        }
        else{
            profit += w*(double)items[i].second/items[i].first ;
            break ;
        }
    }
    return profit ;
}

int main() {
    int testCases; cin >> testCases ;
    while(testCases--){
        int n,w ;
        cin >> n >> w ;
        int weight,value  ;
        vector<pair<int,int>> items ;
        for(int i=0 ; i<n ; i++){
            cin >> weight ;
            pair<int,int> knnc ; knnc.first = weight ;
            knnc.second = 0 ;
            items.emplace_back(knnc) ;
        }
        for(int i=0 ; i<n ; i++){
            cin >> value ;
            items[i].second = value ;
        }
        cout << maximumValue(items, n, w) << endl ;
    }
}
