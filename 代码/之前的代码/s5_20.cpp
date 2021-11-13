#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,i,q,p,w,e,r,n=0;
	r=2147483646;
	for(a=2;a<=r;a=a+2)
	{
		for(i=4;i*i<=a;i++)
		{
			q=a-i;
			for(p=2;p*p<=i;p++)
				if(i%p==0)
  					break;
  				
  			for(e=2;e*e<=q;e++)
				if(q%e==0)
  					break;
  				
  			if(p*p>i&&e*e>q) break; 
		}
		if(a!=i+p)
		n++;
	}
	if(n!=0)
	cout<<"Yes";
	getchar();
	getchar();
	return 0;
}
