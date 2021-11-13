#include<bits/stdc++.h>
using namespace std;

int main(){
	int tot=0;
	char s;
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	s=getchar();
	while(s!='\n'){
		if(s!=' ')tot++;
		s=getchar();
	}
	printf("%d",tot);
	return 0;
}
