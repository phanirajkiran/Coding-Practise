#include <iostream>
using namespace std;
void moveZerosToEnd(int arr[],int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            arr[count++] = arr[i];
        }
    }
    while(count < n){
        arr[count++] = 0;
    }
}
void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        moveZerosToEnd(arr,n);
        printArray(arr,n);
    }
    return 0;
}
