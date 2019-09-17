#include <iostream>
using namespace std;
bool M[100][100];
int n,m;
struct Cell{
    int a,b;
};
bool isValid(int x,int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}
Cell out;
void dfs(int x,int y,int d){
    if(M[x][y]){
        if(d == 1){
            M[x][y] = 0;
            if(!isValid(x+1,y)){
                out.a = x,out.b = y;
                return;
            }
            dfs(x+1,y,2);
        }
        else if(d == 2){
            M[x][y] = 0;
            if(!isValid(x,y-1)){
                out.a = x,out.b = y;
                return;
            }
            dfs(x,y-1,3);
        }
        else if(d == 3){
            M[x][y] = 0;
            if(!isValid(x-1,y)){
                out.a = x,out.b = y;
                return;
            }
            dfs(x-1,y,4);
        }
        else if(d == 4){
            M[x][y] = 0;
            if(!isValid(x,y+1)){
                out.a = x,out.b = y;
                return;
            }
            dfs(x,y+1,1);
        }
    }
    else{
        if(d == 1){
            if(!isValid(x,y+1)){
                out.a = x,out.b = y;
                return;
            }
            dfs(x,y+1,1);
        }
        else if(d == 2){
            if(!isValid(x+1,y)){
                out.a = x,out.b = y;
                return;
            }
            dfs(x+1,y,2);
        }
        else if(d == 3){
            if(!isValid(x,y-1)){
                out.a = x,out.b = y;
                return;
            }
            dfs(x,y-1,3);
        }
        else if(d == 4){
            M[x][y] = 0;
            if(!isValid(x-1,y)){
                out.a = x,out.b = y;
                return;
            }
            dfs(x-1,y,4);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>M[i][j];
            }
        }
        dfs(0,0,1);
        cout<<out.a<<" "<<out.b<<endl;
    }
    return 0;
}
