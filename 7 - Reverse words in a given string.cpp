#include <stdio.h>
void reverse(char* begin, char* end){
	char temp;
	while(begin < end){
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}
void reverseWords(char* s){
	char *word_begin = s;
	char *temp = s;
	// reverse individual words
	while(*temp){
		temp++;
		if(*temp == '\0'){
			reverse(word_begin,temp-1);
		}
		else if(*temp == ' '){
			reverse(word_begin,temp-1);
			word_begin = temp + 1;
		}
	}
	// reverse whole string
	reverse(s, temp - 1);
}
int main(){
	char s[] = "i like this program very much";
	char *temp = s;
	reverseWords(s);
	printf("%s\n",s);
	return 0;
}
