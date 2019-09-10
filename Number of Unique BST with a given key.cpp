#include <iostream>
using namespace std;
int numberOfBST(int n){
	int dp[n+1];
	for(int i=0; i<=n; i++) dp[i] = 0;
	dp[0] = dp[1] = 1;
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			// left subtree number * right subtree number
			dp[i] += dp[i - j] * dp[j - 1];
		}
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	cout << "Number of Unique BST with "<<n<<" keys are : " <<numberOfBST(n)<<"\n";
	return 0;
}
