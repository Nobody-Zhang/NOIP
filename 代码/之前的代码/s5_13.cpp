#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,g=0,q=0,w=0;
	double m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin>>m;
		if(m>100);
		else if(m>85)
			q++;
		else if(m>60)
			g++;
		else
			w++;
	}
	printf("85-100分段%d 60-85分段%d 60分以下分段%d",q,g,w);
	return 0;
}
