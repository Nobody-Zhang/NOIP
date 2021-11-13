#include<bits/stdc++.h>
using namespace std;
char a[1005];
int main()
{
	int n;
	gets(a);
	n=strlen(a);
	for(int s=1;s<n-1;s++)
	 for(int o=1;o<n-1-s;o++)
	  if(a[o]>a[o+1])
	   swap(a[o],a[o+1]);
	puts(a);
	return 0;
}
