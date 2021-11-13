#include<bits/stdc++.h>
using namespace std;

int main()
{
	char a[100];
	gets(a);
	int len=strlen(a);
	
	for(int i=0;i<len;i++)
	{
		b=a[i];
		if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]=(26-(b-64)+1)+64;
		}
		if(a[i]>='a'&&a[i]<='z')
		{
			a[i]=(26-(b-96)+1)+96;
		}
	}
	puts(a);
	return 0;
}
