#include<bits/stdc++.h>
using namespace std;
char fh[]={' ','+','-','*','/'},mid[50];
int in[50],tmp[50],nummid;
bool used[50];
/*template <typename T>inline void redi(T& t)
{
	register int c=getchar();t=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t*=10+c-'0',c=getchar();
	return;
}
template <typename T,typename... Args>inline void redi(T&t,Args&... args)
{
	redi(t);
	redi(args...);
}*/
void print()
{
	cout<<in[1]<<mid[1]<<in[2]<<"="<<in[3]<<endl;
	cout<<in[3]<<mid[2]<<in[4]<<"="<<in[4]<<endl;
	cout<<in[4]<<mid[3]<<in[5]<<"="<<in[6]<<endl;
	exit(0);
}
void dfs(int a,int b)
{
	if(in[0]==6){
		if(in[in[0]]==24)
		 print();
		return;
	}
	for(int i=1;i<=4;i++)
	 {
	 	if(fh[i]=='+')
	 	{
	 		mid[++nummid]=fh[i];
	 		in[0]++;
	 		in[in[0]]=a+b;
	 		for(int j=1;j<=in[0];j++)
	 		 if(used[j]==false)
	 		 {
	 		 	used[j]=true;
	 		 	for(int k=1;k<=in[0];k++)
	 		 	{
	 		 		if(used[k]==false)
	 		 		 {
	 		 		 	used[k]=true;
	 		 		 	dfs(in[j],in[k]);
	 		 		 	dfs(in[k],in[j]);
	 		 		 	used[k]=false;
	 		 		 }
	 		 	}
	 		 	used[j]=false;
	 		 }
	 		 in[0]--;
	 		 nummid--;
	 	}
	 	if(fh[i]=='-')
	 	{
	 		mid[++nummid]=fh[i];
	 		in[0]++;
	 		in[in[0]]=a-b;
	 		for(int j=1;i<=in[0];j++)
	 		 if(used[j]==false)
	 		 {
	 		 	used[j]=true;
	 		 	for(int k=1;k<=in[0];k++)
	 		 	{
	 		 		if(used[k]==false)
	 		 		 {
	 		 		 	used[k]=true;
	 		 		 	dfs(in[j],in[k]);
	 		 		 	dfs(in[k],in[j]);
	 		 		 	used[k]=false;
	 		 		 }
	 		 	}
	 		 	used[j]=false;
	 		 }
	 		 in[0]--;
	 		 nummid--;
	 	}
	 	if(fh[i]=='*')
	 	{
	 		mid[++nummid]=fh[i];
	 		in[0]++;
	 		in[in[0]]=a*b;
	 		for(int j=1;i<=in[0];j++)
	 		 if(used[j]==false)
	 		 {
	 		 	used[j]=true;
	 		 	for(int k=1;k<=in[0];k++)
	 		 	{
	 		 		if(used[k]==false)
	 		 		 {
	 		 		 	used[k]=true;
	 		 		 	dfs(in[j],in[k]);
	 		 		 	dfs(in[k],in[j]);
	 		 		 	used[k]=false;
	 		 		 }
	 		 	}
	 		 	used[j]=false;
	 		 }
	 		 in[0]--;
	 		 nummid--;
	 	}
	 	if(fh[i]=='/'&&b!=0)
	 	{
	 		mid[++nummid]=fh[i];
	 		in[0]++;
	 		in[in[0]]=a/b;
	 		for(int j=1;i<=in[0];j++)
	 		 if(used[j]==false)
	 		 {
	 		 	used[j]=true;
	 		 	for(int k=1;k<=in[0];k++)
	 		 	{
	 		 		if(used[k]==false)
	 		 		 {
	 		 		 	used[k]=true;
	 		 		 	dfs(in[j],in[k]);
	 		 		 	dfs(in[k],in[j]);
	 		 		 	used[k]=false;
	 		 		 }
	 		 	}
	 		 	used[j]=false;
	 		 }
	 		 in[0]--;
	 		 nummid--;
	 	}
	 }
}
int main()
{
	memset(in,0,sizeof(in));
	memset(used,false,sizeof(used));
	memset(tmp,0,sizeof(tmp));
	memset(mid,0,sizeof(mid));
	in[0]=4;
	cin>>in[1]>>in[2]>>in[3]>>in[4];
	/*redi(in[1],in[2],in[3],in[4]);
	char fh[]={' ','+','-','*','/'},mid[50];
	int in[50],tmp[50],nummid;
	bool used[50];*/
	for(int i=1;i<=4;i++)
	{
		used[i]=true;
		for(int j=1;j<=in[0];j++)
		 if(used[j]==false)
		  {
		  	used[j]=true;
		  	dfs(in[i],in[j]);
		  	dfs(in[j],in[i]);
		  	used[j]=false;
		  }
		used[i]=false;
	}
	cout<<"No answer!"<<endl;
	return 0;
}
