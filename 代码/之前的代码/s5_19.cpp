#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a;
	cin>>a;
	if(a>='a'&&a<'v'||a>='A'&&a<='V')
		a=a+4;
	if((a>='w'&&a<='z')||(a>='W'&&a<='Z'))
		a=a-22;
	printf("%c",a);
	return 0;
}
