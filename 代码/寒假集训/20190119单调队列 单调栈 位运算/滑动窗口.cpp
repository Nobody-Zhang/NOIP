#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int m,n,maxx[N],in[N],minn[N];
int tpmx[N],tpmn[N],hmn,tmn,hmx,tmx;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	 cin>>in[i];
	if(n==1)
	 {
	 	for(int i=1;i<=2;i++){
	 		for(int j=1;j<=m;j++)
			 cout<<in[j]<<" ";
			cout<<endl;
	 	}
	 	return 0;
	 }
	hmn=hmx=1,tmn=tmx=0;
	for(int i=1;i<=m;i++)
	{
		while(hmx<=tmx&&i-tpmx[hmx]>=n) hmx++;//头出队列 
		while(hmn<=tmn&&i-tpmn[hmn]>=n) hmn++;
		if(i>=n) {
			maxx[i-n+1]=max(in[tpmx[hmx]],in[i]);
			minn[i-n+1]=min(in[tpmn[hmn]],in[i]);
		}
		while(hmx<=tmx&&in[i]>=in[tpmx[tmx]]) tmx--;
		while(hmn<=tmn&&in[i]<=in[tpmn[tmn]]) tmn--;
		tpmx[++tmx]=i;
		tpmn[++tmn]=i;
	}
	for(int i=1;i<=m-n+1;i++)
	 cout<<minn[i]<<" ";
	cout<<endl;
	for(int i=1;i<=m-n+1;i++)
	 cout<<maxx[i]<<" ";
	return 0;
}
