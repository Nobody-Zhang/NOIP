#include<bits/stdc++.h>
using namespace std;
char a[10];
int main()
{
	for(int i=1;i<=3;i++)
		a[i]=getchar();
	swap(a[1],a[3]);
	cout<<a[1]<<a[2]<<a[3]<<endl;
	return 0;
}