#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define N 35
char fir[N],las[N];
int inc,length;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	gets(fir);
	gets(las);
	for(int i=36;i>0;i--)
	 {
	 	fir[i]=fir[i-1];
	 	las[i]=las[i-1];
	 }
	for(int i=36;i>=0;i--)
	{
		if(fir[i]!=0)
		 {
		 	length=i;
		 	break;
		 }
	}
	int tmp=0;
	for(int i=1;i<=length;i++)
	 {
	 	for(int j=length;j>=1;j--)
	 	 if(fir[i]==las[j]&&fir[i+1]==las[j-1])
	 	  tmp++;
	 }
	long long ans=(1<<tmp);
	cout<<ans<<endl;
	return 0;
}
