#include<bits/stdc++.h>
using namespace std;
char a[1005],b[1005]; 
int main()
{
	gets(a);
	
	int len=strlen(a);
	for(int p=0;p<=len;p++)
		b[len-p-1]=a[p];
	if(strcmp(a,b)==0)
	cout<<"回文";
	else
	cout<<"不是回文"; 
}
