#include<bits/stdc++.h>
using namespace std;
#define MAXX 100003
int n,m,direction[MAXX],t;//n个人，m条指令
string s[MAXX];//逆时针给的，所以逆时针++，顺时针就--
void judge(int a,int ste)
{//a是向左/右，ste是走过的步数
	if(direction[t]+a==1){
		//逆时针，+
		t=(t+ste)%n;
		return;
	}
	t=t-ste;
	while(t<0)
		t+=n;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>direction[i]>>s[i];
	t=0;//指针先指向0
	for(int j=1;j<=m;j++)
	{//0是左，1是右
		int a,ste;
		cin>>a>>ste;
		judge(a,ste);
	}
	cout<<s[t];
	return 0;
}