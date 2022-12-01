// PROBLEM LINK --- https://leetcode.com/problems/maximum-units-on-a-truck/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>a,vector<int>b){
    return a[1] > b[1] ;
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &x,vector<int> &y){
        return x[1]>y[1];
    });
    int ans = 0; int i= 0;
    for(i=0; i<boxTypes.size() && truckSize ; i++){
        if(truckSize - boxTypes[i][0] > 0 ){
            truckSize -= boxTypes[i][0] ;
            ans += boxTypes[i][0] * boxTypes[i][1] ;
        }
        else break ;
    }
    if(i<boxTypes.size()) ans += (truckSize*boxTypes[i][1]) ;
    return ans ;
}
int main(){
    int testCases; cin >> testCases ;
    while(testCases--){
    int n; cin >> n ;
    vector<vector<int>> boxTypes;
    vector<int> noOfBoxes(n) ;
    vector<int> noOfUnitsPerBox(n) ;
    for(int i=0 ;i<n ; i++) cin >> noOfBoxes[i] ;
    for(int i=0 ; i<n ; i++) cin >> noOfUnitsPerBox[i] ;
    for(int i=0 ; i<n ; i++){
        vector<int> knnc ;
        knnc.emplace_back(noOfBoxes[i]) ;
        knnc.emplace_back(noOfUnitsPerBox[i]) ;
        boxTypes.emplace_back(knnc) ;
    }
    int truckSize ; cin >> truckSize ;
    cout << maximumUnits(boxTypes,truckSize) << endl ;
    }
    return 0 ;
}
