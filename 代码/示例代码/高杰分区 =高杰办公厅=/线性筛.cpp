#include<bits/stdc++.h>
using namespace std;
bool shuzip[10000005]={true};
int jilu[5000005],tot=0;
void shai(int M)
{
	for(int i=2;i<=M;i++)
{
		if(shuzip[i]==true)
	 {
		tot++;
		jilu[tot]=i;
		for(int t=2;t<=i;t++)
		{
			shuzip[i*t]=false;
	    	if(t*i>M)
			break;
		}
	 }
		
		if(!shuzip[i])
	{
		if(i*2<=M)
		shuzip[i*2]=false;
	}
}
	return;
}
int main()
{
    int N,n,k;
	scanf("%d",&N);
//	memset(shuzip,true,sizeof(shuzip));//false is 0 true is 1
	shai(N);
	shuzip[1]=false;
	scanf("%d",&n);
	for(int s=1;s<=n;s++)
	{
		scanf("%d",&k);
		if(shuzip[k]==true)
		printf("Yes\n");
		else printf("No\n");
	}
	
 return 0;
}
