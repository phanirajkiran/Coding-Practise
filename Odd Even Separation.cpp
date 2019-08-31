#include <bits/stdc++.h>
using namespace std;
stack<int> stOdd, stEven;
void Function(){
	if(stOdd.size() > 0){
		int x = stOdd.top();
		stOdd.pop();
		Function();
		if(x % 2 == 0) stEven.push(x);
		else stOdd.push(x);
	}
}
int main(){
    int n,a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        stOdd.push(a);
    }
    Function();
    while(!stOdd.empty()){
		cout<<stOdd.top()<<" ";
		stOdd.pop();
	}
	cout<<endl;
	while(!stEven.empty()){
		cout<<stEven.top()<<" ";
		stEven.pop();
	}
	return 0;
}
