#include <iostream>
#include <stack>
using namespace std;
const int MAX = 100;
void dfs(int i,int V,bool G[][MAX],stack<int> &s,bool vis[]){
    vis[i] = 1;
    for(int j=0; j<V; j++){
        if(G[i][j] && !vis[j]){
            dfs(j,V,G,s,vis);
        }
    }
    s.push(i);
}
int* topoSort(int V,bool G[][MAX]){
    static int a[100];
    stack <int> s;
    bool vis[V] = {0};
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i,V,G,s,vis);
        }
    }
    for(int i=0; i<V; i++){
        a[i] = s.top();
        s.pop();
    }
    return a;
}
int main(){
    int t; cin>>t;
	bool G[MAX][MAX];
	while(t--){
		int n; cin>>n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>G[i][j];
			}
		}
        int *res = topoSort(n,G);
        for(int i=0; i<n; i++){
            cout<< res[i] << " ";
        }
        cout<<"\n";
    }
    return 0;
}
