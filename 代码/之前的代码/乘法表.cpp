#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int k,p,h;
	  for(k=1;k<=9;k++)
	    {
	    	for(p=1;p<=k;p++)
	    	  {
	    	  	h=p*k;
	    	  	printf("%d*%d=%d ",k,p,h);
	    	  }
	        printf("\n");
		}
    return 0;
}
