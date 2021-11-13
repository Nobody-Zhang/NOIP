#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,char x,char y,char z)
{
	if(n==1)
	{
		printf("%d:%c->%c\n",n,x,z);
		return;
	}
	hanoi(n-1,x,z,y);
	printf("%d:%c->%c\n",n,x,z);
	hanoi(n-1,y,x,z);
}
int main()
{
	int m;
	cin>>m;
	hanoi(m,'A','B','C');
	return 0;
}
