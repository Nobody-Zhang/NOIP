#include<bits/stdc++.h>
using namespace std;

int cnt;

int main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	char ch;
	/*char c;
	ch=getchar();
	c=getchar();
	printf("%d %d",ch,c);*/
	while((ch=getchar())!=EOF){
		if(ch!=32&&ch!=10) cnt++;
	}
	printf("%d",cnt);
}
