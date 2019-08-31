// C++ code to reverse a
// stack without using extra stack
#include <bits/stdc++.h>
using namespace std;
stack<int> st;
void insert_at_bottom(int x){
	if(st.size() == 0) st.push(x);
	else{
		int a = st.top();
		st.pop();
		insert_at_bottom(x);
		st.push(a);
	}
}
void Reverse(){
	if(st.size() > 0){
		int x = st.top();
		st.pop();
		Reverse();
		insert_at_bottom(x);
	}
}
int main(){
    int n,a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        st.push(a);
    }
	Reverse();
	cout<<"Reversed Stack"<<endl;
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
