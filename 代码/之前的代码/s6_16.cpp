#include<bits/stdc++.h>
using namespace std;
char a[1005],t;
int main()
{
	gets(a);
	int cd=strlen(a);
	for(int i=0;i<=cd/2;i++)
	 {
	 	t=a[i];
	 	a[i]=a[cd-i-1];
	 	a[cd-i-1]=t;
	 }
	puts(a);
	return 0;
}
