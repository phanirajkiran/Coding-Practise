/*
we have a series of n daily price quotes for a stock and
we need to calculate span of stocks price for all n days.
The span Si of the stocks price on a given day i is defined
as the maximum number of consecutive days just before the given day,
for which the price of the stock on the current day is less than
or equal to its price on the given day.
*/
#include <iostream>
#include <stack>
using namespace std;
void calculateSpan(int price[],int n,int S[]){
	stack<int> st;
	st.push(0);
	S[0] = 1;
	for(int i=1; i<n; i++){
		while(!st.empty() && price[st.top()] <= price[i]) st.pop();
		S[i] = (st.empty()) ? (i + 1) : (i - st.top());
		st.push(i);
	}
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int price[n],S[n];
        for(int i=0; i<n; i++){
            cin>>price[i];
        }
        calculateSpan(price,n,S);
        for(int i=0; i<n; i++){
            cout << S[i] << " ";
        }
        cout<<"\n";
    }
	return 0;
}
