#include<bits/stdc++.h>
using namespace std;
int r[21000005],a[21000005];
int main()
{
	int b,t=0;
	cin>>b;
	for(int c=1;c<=b;c++)
	 if(c%7==0||c%11==0)
	  r[c]=1;
	for(int c=1;c<=b;c++)
	 if(r[c]==1)
	 {
	 	t++;
		a[t]=c;
	 }
	return 0;
}
