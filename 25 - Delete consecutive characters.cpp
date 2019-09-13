#include <iostream>
#include <stack>
using namespace std;
void deleteConsecutiveChar(char *s){
    char *temp = s;
    stack<char>s1,s2;
    while(*temp){
        s1.push(*temp);
        ++temp;
    }
    char curr,prev = ' ';
    while(!s1.empty()){
        curr = s1.top();
        s1.pop();
        if(prev != ' ' && prev != curr){
            s2.push(curr);
        }
        else if(prev == ' ') s2.push(curr);
        prev = curr;
    }
    char *ch = s;
    while(!s2.empty()){
        *ch++ = s2.top();
        s2.pop();
    }
    *ch = '\0';
    return;
}
int main(){
    int t; cin>>t;
    while(t--){
        char s[100]; cin>>s;
        deleteConsecutiveChar(s);
        cout<<s<<endl;
    }
    return 0;
}
