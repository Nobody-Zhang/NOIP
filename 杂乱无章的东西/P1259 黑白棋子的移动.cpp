#include<bits/stdc++.h>
using namespace std;
int n;
void print(int x)
{
	/*
	ooooooo*******--
	oooooo--******o*n=7,x=7
	*/
	if(x==4)
	{
		printf("oooo****--");
		for(int i=1;i<=n-x;i++)
		 printf("o*");cout<<endl;
		printf("ooo--***o*");
		for(int i=1;i<=n-x;i++)
		 printf("o*");cout<<endl;
		printf("ooo*o**--*");
		for(int i=1;i<=n-x;i++)
		 printf("o*");cout<<endl;
		printf("o--*o**oo*");
		for(int i=1;i<=n-x;i++)
		 printf("o*");cout<<endl;
		printf("o*o*o*--o*");
		for(int i=1;i<=n-x;i++)
		 printf("o*");cout<<endl;
		printf("--o*o*o*o*");
		for(int i=1;i<=n-x;i++)
		 printf("o*");cout<<endl;
		//printf("oooo****--o*o*o*\nooo--***o*o*o*o*\nooo*o**--*o*o*o*\no--*o**oo*o*o*o*\no*o*o*--o*o*o*o*\n--o*o*o*o*o*o*o*");
		exit(0);
	}
	for(int i=1;i<=x;i++)
	 printf("o");
	for(int i=1;i<=x;i++)
	 printf("*");
	printf("--");
	for(int i=1;i<=n-x;i++)
	 printf("o*");
	printf("\n");
	//第一串打完了
	for(int i=1;i<=x-1;i++)
	 printf("o");
	printf("--");
	for(int i=1;i<=x-1;i++)
	 printf("*");
	for(int i=1;i<=n-x+1;i++)
	 printf("o*");
	printf("\n");
	print(x-1);
}
int main()
{
	cin>>n;
	print(n);
}