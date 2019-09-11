#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 100000000;
int printSolution(int dis[],int V){
    for(int i=0; i<V; i++){
        printf("%d ",dis[i]);
    }
}
void dijkstra(vector<vector<int>> graph,int src,int V){
    int dis[V];
    bool vis[V];
    for(int i=0; i<V; i++) dis[i] = INF, vis[i] = false;
    priority_queue<pair<int,int> >pq;
    pq.push({0,src});
    dis[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        vis[u] = true;
        pq.pop();
        for(int i=0; i<V; i++){
            if(!vis[i] && graph[u][i]){
                if(dis[u]+graph[u][i] < dis[i]){
                    dis[i] = dis[u] + graph[u][i];
                    pq.push(make_pair(-1*dis[i],i));
                }
            }
        }
    }
    printSolution(dis,V);
}
int main(){
    int t,V,s;
    cin>>t;
    while(t--){
        cin>>V;
        vector<vector<int>> g(V);
        for(int i=0; i<V; i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        for(int i=0; i<V; i++){
      	    for(int j=0; j<V; j++){
      		    cin>>g[i][j];
      	    }
        }
        cin>>s;
        dijkstra(g,s,V);
    }
        return 0;
}
