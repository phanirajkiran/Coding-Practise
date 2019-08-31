// C++ code to sort a
// stack without using extra stack
#include <bits/stdc++.h>
using namespace std;
stack<int> st;
void sortedInsert(int x){
    if(st.empty() || x < st.top()){
        st.push(x);
    }
    else{
        int a = st.top();
        st.pop();
        sortedInsert(x);
        st.push(a);
    }
}
void sortStack(){
	if(st.size() > 0){
		int x = st.top();
		st.pop();
		sortStack();
		sortedInsert(x);
	}
}
int main(){
    int n,a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        st.push(a);
    }
    sortStack();
    while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
