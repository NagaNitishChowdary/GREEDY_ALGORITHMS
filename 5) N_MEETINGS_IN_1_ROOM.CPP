// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <bits/stdc++.h>
using namespace std;
    
bool comp(vector<int>a,vector<int>b){
    return a[1] < b[1] ;
}

int maxMeetings(int start[], int end1[], int n)
{
    /*
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
    */
    pair<int, int> a[n + 1];
	int i;
	for (i = 0; i < n; i++) {
		a[i].first = end1[i];
		a[i].second = i;
	}
	sort(a, a + n);
	int time_limit = a[0].first;
    int maxi = 1 ;
	for (i = 1; i < n; i++) {
		if (start[a[i].second] > time_limit) {
			maxi++ ;
			time_limit = a[i].first;
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
