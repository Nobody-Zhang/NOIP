#include<bits/stdc++.h>
using namespace std;
int age(int n)
{
	if(n==1) return 10;
	return (age(n-1)+2);
} 
int main()
{
	int a,ages;
	cin>>a;
	ages=age(a);
	cout<<ages;
	return 0;
}
