#include<bits/stdc++.h>
using namespace std;
int answer[20],tot,he[100],cha[100],n,zong[100];
void search(int x)//x是第几行
{
	for(int i=1;i<=n;i++)
	{//i定义的是列
		if(he[x+i]==0&&cha[x-i+50]==0&&zong[i]==0){//如果对角没放（he，cha都是0且行为）
			answer[x]=i;
			he[x+i]=1;
			cha[x-i+50]=1;
			zong[i]=1;
			if(x==n){
				tot++;
				if(tot<=3){
					for(int j=1;j<=n-1;j++){
						printf("%d ",answer[j]);
					}
				printf("%d\n",answer[n]);
				}
			}
			search(x+1);
			he[x+i]=0;
			cha[x-i+50]=0;
			zong[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	search(1);
	cout<<tot;
	return 0;
}