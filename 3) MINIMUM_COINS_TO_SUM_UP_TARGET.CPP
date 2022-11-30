// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/975277?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std ;

int findMinimumCoins(int target) 
{
    // Write your code here
    int arr[9] = {1,2,5,10,20,50,100,500,1000} ;
    int minCoins = 0 ;
    int n = 9 ;
    while(target > 0){
        if(target - arr[n-1] >= 0){ minCoins++ ; target -= arr[n-1] ; }
        else n-- ;
    }
    return minCoins ;
}

int main(){
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n ;
        cout << findMinimumCoins(n) << endl ;
    }
}
