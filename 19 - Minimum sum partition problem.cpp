#include <iostream>
using namespace std;
const int MAX = (int)1e9;
int findMin(int arr[],int n){
	// Calculate sum of all elements
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
	// Create an array to store results of subproblems
	bool dp[n+1][sum+1];
	// Initialize first column as true. 0 sum is possible
	// with all elements.
	for(int i=0; i<=n; i++){
		dp[i][0] = true;
	}
	// Initialize top row, except DP[0][0], as false. With
	// 0 elements, no other sum except 0 is possible
	for(int i=1; i<=sum; i++){
		dp[0][i] = false;
	}
	// DP[i][j] = 1 if subset from 1 to i has a sum equal to j
    // 0 otherwise
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			dp[i][j] = dp[i-1][j];
			if(arr[i-1] <= j){
				dp[i][j] |= dp[i-1][j-arr[i-1]];
            }
		}
	}
	int diff = MAX;
	for(int j=sum/2; j>=0; j--){
		if(dp[n][j]){
			diff = max(sum-j,j)-min(sum-j,j);
			break;
		}
	}
	return diff;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout << findMin(arr,n) <<endl;
    }
	return 0;
}
