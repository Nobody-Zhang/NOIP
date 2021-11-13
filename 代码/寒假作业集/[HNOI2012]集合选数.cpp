#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
bool used[maxn];
int mp[20][12],m,ima,jma;
bool judge()
{
	for(int i=1;i<=m;i++)
	 if(!used[i]) return i;
	return 0; 
}
void make_map(int fir)
{
	memset(mp,0,sizeof(mp));
	for(int i=1;fir*pow(3,i-1)<=m;i++)
		for(int j=1;fir*pow(2,j-1)<=m;j++)
		{
			int now=fir*pow(3,i-1)*pow(2,j-1);
			if(now>m) break;
			mp[i][j]=now;
		}
	for(int i=1;fir*pow(3,i-1)<=m;i++){
		ima=max(ima,i);
	}
	for(int j=1;fir*pow(2,j-1)<=m;j++){
		jma=max(jma,j);
	}
	return;
}
void pre()
{
	for(int i=1;i<=(1<<13);i++)
}
int main()
{
	scanf("%d",&m);
	pre();
	while(1){
		ima=jma=0;//ÇåÁã 
		int fir=judge();
		if(!fir) break;
		make_map(fir);
		for(int i=1;i<=ima;i++)//´æ´¢ÐÐÊý 
			for(int j=1;j<=jma;j++)
				{
					if(!mp[i][j]) break;
					
				}
	}
}
