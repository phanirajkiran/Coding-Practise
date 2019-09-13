#include <iostream>
using namespace std;
int maxSubArraySum(int arr[],int n){
    int mx1, mx2;
    mx1 = mx2 = arr[0];
    for(int i=1; i<n; i++){
		mx1 = max(arr[i],mx1+arr[i]);
		mx2 = max(mx2,mx1);
    }
    return mx2;
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
        int max_sum = maxSubArraySum(arr,n);
        cout << "Maximum contiguous sum is " << max_sum << "\n";
    }
    return 0;
}
