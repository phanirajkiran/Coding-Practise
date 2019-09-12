#include <iostream>
using namespace std;
int occur[3];
int main(){
    int t;
    cin>>t;
    while(t--){
        int N,a;
        cin>>N;
        fill(occur,occur+3,0);
        for(int i=1; i<=N; i++){
            cin>>a;
            occur[a]++;
        }
        for(int i=0; i<3; i++){
            for(int j=1; j<=occur[i]; j++){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
