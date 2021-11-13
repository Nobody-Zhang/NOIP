#include<bits/stdc++.h>
using namespace std;
int main()
{
	int u;
	char a[1005];
	gets(a);
	u=strlen(a);
	for(int o=0;o<u;o++)
	 if(o%2==0&&a[o]>='a'&&a[o]<='z')
	  a[o]=a[o]-32;
	 puts(a);
	 return 0;
}
