#include <iostream>
#include <queue>
using namespace std;
bool arr[100][100], vis[100][100];
int fx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int fy[] = {1, 0, -1, 0, 1, 1, -1, -1};
struct cell{
	int x, y;
};
bool isValid(int x, int y, int n, int m){
	return (x>=0 && y>=0 && x<n && y<m);
}
int bfs(int i, int j, int n, int m){
    int cnt = 1;
    vis[i][j] = true;
    queue<cell> q;
    cell temp, adj;
    temp.x = i;
    temp.y = j;
    q.push(temp);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int k=0; k<8; k++){
            int u = fx[k] + temp.x;
            int v = fy[k] + temp.y;
            if(!vis[u][v] && arr[u][v] && isValid(u,v,n,m)){
                ++cnt;
                adj.x = u;
                adj.y = v;
                q.push(adj);
                vis[u][v] = 1;
            }
        }
    }
    return cnt;
}
int main(){
    int t; cin>>t;
    while(t--){
        int ans = 0;
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && arr[i][j]){
                    ans = max(ans,bfs(i,j,n,m));
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vis[i][j] = 0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
