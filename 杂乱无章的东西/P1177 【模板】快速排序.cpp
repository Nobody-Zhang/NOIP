#include<bits/stdc++.h>
using namespace std;
int s[100001],m;
void kp(int x,int y)
{
	if(x>=y) return;
	int i=x,j=y,tmp=s[x];//最开始来比较
	while(i!=j)
	{
		while(s[j]>=tmp&&i<j) j--;
		while(s[i]<=tmp&&i<j) i++;
		swap(s[i],s[j]);
		//int t=s[i];
		//s[i]=s[j];
		//s[j]=t;
	}
	//int t=s[i];
	//s[i]=s[x];
	//s[x]=t;
	swap(s[i],s[x]);
	kp(x,i-1);
	kp(i+1,y);
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>s[i];
	bool flag=false;
	for(int i=2;i<=m;i++)
		if(s[i]!=s[i-1]){
			flag=true;//如果有不相同的元素
		}
	if(!flag) {
		for(int i=1;i<=m;i++) cout<<s[i]<<" ";
		return 0;
	}
	random_shuffle(s+1,s+m+1); //打乱它 
	kp(1,m);
	for(int i=1;i<=m;i++)
		cout<<s[i]<<" ";
	return 0;
}