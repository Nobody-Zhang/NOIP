//—°‘Ò≈≈–Ú 
#include<bits/stdc++.h>
using namespace std;
int a[11];
int main()
{
	int q;
	for(q=1;q<=10;q++)
	scanf("%d",&a[q]);
	for(int i=1;i<10;i++)
		for(int j=i+1;j<=10;j++)
		if(a[i]<a[j]) swap(a[i],a[j]);
	for(q=1;q<=10;q++)
	printf("%d ",a[q]);
}
