#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int j,i,a[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	cin>>j>>i;
	if(j%100!=0&&j%4==0||j%400==0) a[2]=29;
	cout<<a[i];
}
