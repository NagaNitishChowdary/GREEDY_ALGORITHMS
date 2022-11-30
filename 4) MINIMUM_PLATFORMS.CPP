// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_799400

// TIME COMPLEXITY --- O(2NLOGN) + O(2N)
// SPACE COMPLEXITY --- O(1)

#include<bits/stdc++.h>
using namespace std ;

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n) ;
    sort(dt,dt+n) ;
    int maxi = 1 ;
    int platform_needed = 1 ;
    int i=1 , j=0 ;
    while(i<n && j<n){
        if(at[i] <= dt[j]){
            platform_needed++ ;
            i++ ;
        }
        else if(at[i] > dt[j]){
            platform_needed-- ;
            j++ ;
        }
        if(platform_needed > maxi) maxi = platform_needed ;
    }
    
    return maxi ;
}

int main()
{
    int testCases; cin >> testCases ;
    while(testCases--){
        int n; cin >> n ;
        int at[n] , dt[n] ;
        for(int i=0 ; i<n ; i++) cin >> at[i] ;
        for(int i=0 ; i<n ; i++) cin >> dt[i] ;
        cout << calculateMinPatforms(at,dt,n) << endl ;
    }
}
