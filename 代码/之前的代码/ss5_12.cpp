#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,i,j,w;
   scanf("%d",&n);
    printf("2 ");
    for(i=3;i<=n;i++)
    {
    	w=0;
    	for(j=2;j<=i-1;j++)
    	{
    		if(i%j==0)
    		w++;
    	}
    	if(w==0)
    	printf("%d ",i);	
    }
	return 0;
}
