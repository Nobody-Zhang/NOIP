#include<bits/stdc++.h>
using namespace std;
char in[1001],fh[1001];
int sz[1001],hin,hfh,hsz,kh[10001][3],tmp,totad,totmi;
void kk(int l,int len);
void add(int l,int r,int fhgs)
{
	while(fhgs>=1)
	{
		if(fh[hfh]=='+')
		{
			hsz--;
			sz[hsz]+=sz[hsz+1];
			sz[hsz+1]=0;
			fh[hfh]=' ';
			hfh--;
			fhgs--;
		}
		if(fh[hfh]=='-')
		{
			hsz--;
			sz[hsz]-=sz[hsz+1];
			sz[hsz+1]=0;
			fh[hfh]=' ';
			hfh--;
			fhgs--;
		}
	}
}
int bfs(int i,int jj)
{
	if(in[i]=='(') {
		tmp++;
		kk(kh[tmp][1]+1,kh[tmp][2]);
		int tail=kh[tmp][1];
		while(sz[hsz]!=0)
		{
			in[tail]=sz[hsz]%10+'0';
			tail++;
			sz[hsz]/=10;
			totmi++;
		}
		tail--;
		totmi--;
		for(int j=kh[tmp][1];j<=(tail+kh[tmp][1])/2;j++)
		 swap(in[j],in[tail+kh[tmp][1]-j]);
		for(int j=kh[tmp][1]+totmi;j<=jj;j++)
		 {
			 in[j]=in[j+jj-];///gfsdffdsf
			 tail++;
		 }
		totad=tail;
		return -1;
	}
	hsz++;
	while(in[i]>='0'&&in[i]<='9')
	{
		sz[hsz]*=10;
		sz[hsz]+=in[i]-'0';
		i++;
	}
	return i;
}
void kk(int l,int r)
{
	int aa=0;
	for(int i=l;i<=r;i++)
	switch(in[i])
	{
		case'+':fh[++hfh]=in[i];aa++;break;
		case'-':fh[++hfh]=in[i];aa++;break;
		case'*':{
			int lk=bfs(i+1);
			if(lk!=-1)
			 i=lk-1;
			if(lk==-1)
			 r=totad;
			sz[--hsz]*=sz[hsz+1];sz[hsz+1]=0;
			break;
		}
		case'/':{
			i=bfs(i+1)-1;
			sz[--hsz]/=sz[hsz+1];
			sz[hsz+1]=0;
			break;
		}
		case'(':{
			i++;
			tmp++;
			kk(kh[tmp][1],kh[tmp][2]);
			break;
		}
		case')':{
			add(kh[tmp][1],kh[tmp][2],aa);
			return;
		}
		default:i=bfs(i)-1;
	}
}
int main()
{
	gets(in);
	int len=strlen(in);
	for(int i=len;i>=1;i--)
	 in[i]=in[i-1];
	in[0]='\000';
	for(int i=1;i<=len;i++)
	 if(in[i]=='(')
	  kh[++kh[0][1]][1]=i;
	for(int j=len;j>=1;j--)
	 if(in[j]==')')
	  kh[++kh[0][2]][2]=j;
	kk(1,len);
	while(hsz!=1)
	{
		if(fh[hfh]=='+')
		{
			hfh--;
			hsz--;
			sz[hsz]+=sz[hsz+1];
		}
		if(fh[hfh]=='-')
		{
			hfh--;
			hsz--;
			sz[hsz]-=sz[hsz+1];
		}
	}
	cout<<sz[hsz]<<endl;
	return 0;
}
