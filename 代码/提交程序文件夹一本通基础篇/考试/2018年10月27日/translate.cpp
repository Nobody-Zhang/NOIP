#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int m,n,now,tot;
int dc[105],art[1005];
int main()
{
	freopen("translate.in","r",stdin);
	freopen("translate.out","w",stdout);
	cin.tie(0);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	 {
	 	cin>>art[i];
	 	art[i]++;//�ӣ��С�0����һ�����Ե����棡���� 
	 	//ȫ��+1��Over�� 
	 }
	for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=m;j++)
	 	 {
	 	 	if(art[i]==dc[j]) break;
	 	 	if(j==m)
	 	  {
	 	  	if(now<m)
	 	  	{
	 	  		now++;
	 	  		dc[now]=art[i];
	 	  		tot++;
	 	  	}
	 	  	else
	 	  	{
	 	  		now=1;
	 	  		dc[now]=art[i];
	 	  		tot++;
	 	  	}
	 	  }
	 	  
	 	 }
	 }
	 cout<<tot<<endl;
	 return 0;
}
