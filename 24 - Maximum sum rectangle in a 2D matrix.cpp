#include <iostream>
using namespace std;
const int MIN = (int)-1e9;
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
    int t;
    cin>>t;
    while(t--){
        int rows,columns,ans = MIN;
        cin>>rows>>columns;
        int mat[rows][columns];
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                cin>>mat[i][j];
            }
        }
        int arr[rows];
        for(int l=0; l<columns; l++){
            fill(arr,arr+rows,0);
            for(int r=l; r<columns; r++){
                for(int i=0; i<rows; i++){
                    arr[i] += mat[i][r];
                }
                ans = max(ans,maxSubArraySum(arr,rows));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
