#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
#define mod 233333
#define boot 1723333
#define jump 107
unsigned long long in[maxn];
int n,m,hash1[maxn*30+1];
void hash(unsigned long long data)
{
	unsigned long long tmp=data*boot*boot*boot+boot*2;
	tmp%=mod;
	while(hash1[tmp]!=-1){
		tmp+=jump;
	}
	if(hash1[tmp]==-1)
		hash1[tmp]=data;
	return;
}
bool search(unsigned long long data)
{
	unsigned long long tmp=data*boot*boot*boot+boot*2;
	tmp%=mod;
	while(hash1[tmp]!=-1&&hash1[tmp]!=data){
		tmp+=jump;
	}
	if(hash1[tmp]==-1) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=maxn*30;i++)
		hash1[i]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>in[i];
		hash(in[i]);
	}
	for(int i=1;i<=m;i++)
	{
		unsigned long long inc;
		cin>>inc;
		if(search(inc)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
