#include<bits/stdc++.h>
using namespace std;
int main (){
	char a,b;
	scanf("%c",&a);
	if(a>='A'&&a<='Z')
		printf("%c",a);
	else
		{
		printf("%c",a-32);
		}
	return 0;
}
