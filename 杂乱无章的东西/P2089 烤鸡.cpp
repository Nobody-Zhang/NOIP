#include<bits/stdc++.h>
using namespace std;
int m,s[11],tot;
void search1(int now,int rest)
{
	/*if(rest>3*(10-now)){
		return;
	}*/
	if(now==10){
		if(rest>3||rest<=0) return;
	}
	if(now==10)
	{
		for(int i=1;i<=9;i++)
			printf("%d ",s[i]);
		 //cout<<s[i]<<" ";
		printf("%d\n",rest);
		return;
	}
	if(rest<=0) return;
	for(int i=1;i<=3;i++)
	{
		s[now]=i;
		search1(now+1,rest-i);
		s[now]=0;
	}
	return;
}
void search2(int now,int rest)
{
	/*if(rest>3*(10-now)){
		return;
	}*/
	//if(rest<=0) return;
	if(now==10){
		if(rest>3||rest<=0) return;
	}
	if(now==10)
	{
		tot++;
		return;
	}
	
	if(rest<=0) return;
	for(int i=1;i<=3;i++)
	{
		s[now]=i;
		search2(now+1,rest-i);
		s[now]=0;
	}
	return;
}
int main()
{
	cin>>m;
	if(m>30||m<10){
		cout<<"0";
		return 0;
	}
	search2(1,m);
	cout<<tot<<endl;
	search1(1,m);
	return 0;
}