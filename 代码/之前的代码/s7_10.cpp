#include<bits/stdc++.h>
using namespace std;
int jc(int i)
{
	if(i==1) return 1;
	return jc(i-1)*i;
}
int main()
{
	int o,op;
	cin>>o;
	op=jc(o);
	cout<<op;
	return 0;
}
