#include <bits/stdc++.h>
using namespace std;
    
bool comp(vector<int>a,vector<int>b){
    return a[1] < b[1] ;
}

int maxMeetings(int start[], int end1[], int n)
{
    vector<vector<int>> knnc ;
    for(int i=0 ; i<n ; i++){
    vector<int> vt ; vt.emplace_back(start[i]) ; vt.emplace_back(end1[i]) ;
    knnc.emplace_back(vt) ;  }
    sort(knnc.begin(),knnc.end(),comp) ;
    int maxi = 1 , limit = knnc[0][1] ;
    for(int i=1 ; i<n ; i++){
        if(knnc[i][0] > limit){
            maxi++ ;
            limit = knnc[i][1] ;
        }
    }
    return maxi ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end1[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end1[i];

        int ans = maxMeetings(start, end1, n);
        cout << ans << endl;
    }
    return 0;
}
