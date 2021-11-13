#include<bits/stdc++.h>
using namespace std;
char in[256],tmp[256];
int topin,toptmp,lll;
int main()
{
	freopen("strs.in","r",stdin);
	freopen("strs.out","w",stdout);
	int m;
	scanf("%d",&m);
	for(int p=1;p<=m;p++)
	{
		memset(in,0,sizeof(in));
		memset(tmp,0,sizeof(tmp));
		lll=0;
		topin=0;
		toptmp=0;
		scanf("%s",&in);
	int m=strlen(in);
	for(int i=m;i>=0;i--)
	 in[i+1]=in[i];
	int k=0,j=0;
	for(int i=1;i<=m;i++)
	{
		if(in[i]=='('||in[i]=='{'||in[i]=='[')
		 k++;
		if(in[i]==')'||in[i]=='}'||in[i]==']')
		 j++;
	}
	if(k!=j) {
		cout<<"NO"<<endl;
		continue;
	}
	for(int i=1;i<=m;i++)
	 {
	 	if(in[i]=='('||in[i]=='{'||in[i]=='[')
	 	 ++toptmp,tmp[toptmp]=in[i];
	 	else
	 	{
	 		if(in[i]==')'&&tmp[toptmp]=='(')
	 		{
	 			toptmp--;
				 continue;
	 		}
	 		if(in[i]==']'&&tmp[toptmp]=='[')
	 		{
	 			toptmp--;
				 continue;
	 		}
	 		if(in[i]=='}'&&tmp[toptmp]=='{')
	 		{
	 			toptmp--;
				 continue;
	 		}
	 	}
	 }
	 if(toptmp==0) cout<<"YES"<<endl;
	 if(toptmp!=0) cout<<"NO"<<endl;
	}
	 return 0;
}
