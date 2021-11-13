#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long lxl,prime=2,q,i=1;
	for(lxl=4;lxl>=4;lxl=lxl+2)
      {
	    
		for(i=1;i*i<=prime;i++)
          {
            if (prime%i==0) break;
          }
          printf("YES?");
	    if (i*i>prime)
	      q=lxl-prime;
	    for(i=1;i*i<=q;i++)
          {
            if (q%i==0)
            printf("right?");
          }
	    if (i*i>q)
	      printf("YES!");
      }
	return 0;
}

