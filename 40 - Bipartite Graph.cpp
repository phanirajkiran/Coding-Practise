#include <iostream>
using namespace std;
const int MAX = 100;
bool dfs(int G[][MAX],int V,int par,int src,int color[]){
    if(par == src) return false;    // self loop
    if(par == -1) color[src] = 1;
    bool temp = true;
    for(int v=0; v<V; v++){
        if(G[src][v] && color[v] == -1){
            color[v] = 1 - color[src];
            temp = temp && dfs(G,V,src,v,color);
        }
        else if(G[src][v] && color[v] == color[src]) return false;
    }
    return temp;
}
bool isBipartite(int G[][MAX],int V){
     int color[V];
     fill(color,color+V,-1);
     for(int i=0; i<V; i++){
         if(color[i] == -1){
            if(dfs(G,V,-1,i,color) == false){
               return false;
            }
         }
     }
     return true;
}
int main(){
    int t; cin>>t;
	int G[MAX][MAX];
	while(t--){
		int n; cin>>n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>G[i][j];
			}
		}
		cout<<isBipartite(G,n)<<endl;
	}
	return 0;
}
