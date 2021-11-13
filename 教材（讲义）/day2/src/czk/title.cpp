#include<bits/stdc++.h>
using namespace std;
char a[10005];
int n=0;
int main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	gets(a);
	n=strlen(a);
	for(int i=0;i<=n;i++){
		if(a[i]==' ')n--;
	}
	cout<<n;
	return 0;
}
