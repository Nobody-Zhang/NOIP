#include<stdio.h>

int cnt=0;
inline bool check(char c){
	if(c>='0'&&c<='9') return true;
	else if(c>='a'&&c<='z') return true;
	else if(c>='A'&&c<='Z') return true;
	return false;
}
int main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	for(int i=1;i<=5;i++){
		char c=getchar();
		if(check(c)) cnt++;
	}
	printf("%d",cnt);
}
