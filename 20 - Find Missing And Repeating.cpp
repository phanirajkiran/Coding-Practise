#include <iostream>
using namespace std;
const int MAX = 1000001;
int occur[MAX];
int main(){
    int t;
    cin>>t;
    while(t--){
        int N,a,A,B;
        cin>>N;
        fill(occur,occur+N,0);
        A = B = 0;
        for(int i=1; i<=N; i++){
            cin>>a;
            occur[a]++;
        }
        for(int i=1; i<=N; i++){
            if(!occur[i] && !A) A = i;
            if(occur[i] == 2 && !B) B = i;
        }
        cout<<B<<" "<<A<<endl;
    }
    return 0;
}
