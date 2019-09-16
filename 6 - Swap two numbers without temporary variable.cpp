#include <iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        a = a + b;
        b = a - b;
        a = a - b;
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}
