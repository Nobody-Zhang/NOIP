#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib> 
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
long long in[100010],m,fr[100010],maxx,en[100010];
stack<long long> s_en,s_fr;
int main()
{
	while(1)
	{
		cin>>m;
		if(m==0) return 0;
		maxx=-1;
		memset(in,0,sizeof(in));
		for(int i=1;i<=m;i++)
		 cin>>in[i];
		in[m+1]=in[0]=-1;
		memset(fr,0,sizeof(fr));
		memset(en,0,sizeof(en));
		for(int i=0;i<=m+1;i++)
		{
			while(!s_en.empty())
			 if(in[i]<in[s_en.top()])
			  {
			  	en[s_en.top()]=i;
			  	s_en.pop();
			  }
			 else break;
			s_en.push(i);
		}
		for(int i=m+1;i>=0;i--)
		{
			while(!s_fr.empty())
			 if(in[i]<in[s_fr.top()])
			 {
			 	fr[s_fr.top()]=i;
			 	s_fr.pop();
			 }
			 else break;
			s_fr.push(i);
		}
		/*for(int i=1;i<=m;i++)
		 if(en[i]==0) en[i]=m+1;*/
		for(int i=1;i<=m;i++)
		 maxx=max(maxx,in[i]*(en[i]-fr[i]-1));
		cout<<maxx<<endl;
	}
}
