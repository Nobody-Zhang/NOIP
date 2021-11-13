#include<bits/stdc++.h>
using namespace std;
int n,q,l,p,a[1010],w[1010][10];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		int x=a[i],j=1,cm=1;
		while(x){
			w[i][j]=w[i][j-1]+(x%10)*cm;
			j++;cm*=10;
			x/=10;
		}
	}
	for(int i=1;i<=q;i++){
		bool fl=false;
		scanf("%d%d",&l,&p);
		for(int j=1;j<=n;j++)
		if(w[j][l]==p){
			printf("%d\n",a[j]);
			fl=true;break;
		}
		if(fl==false)printf("-1\n");
	}
	return 0;
}
