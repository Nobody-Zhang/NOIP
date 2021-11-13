#include<bits/stdc++.h>
using namespace std;
int n,m,T,s[100005],x,y;
double qw[100007];

int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		memset(s,0,sizeof(s));
		memset(qw,0,sizeof(qw));
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			s[x]=y;
		}
		qw[n-1]=1;qw[n]=0;
		if(s[n-1]){
			qw[n-1]=0;
		}
		for(int i=n-2;i>=0;i--){
			if(s[i]){
				qw[i]=qw[s[i]];continue;
			}
			for(int j=1;j<=6;j++){
				qw[i]+=(qw[i+j]+1)*1.0;
			}
			qw[i]/=6;
		}
		printf("%.2lf\n",qw[0]);
	}
	return 0;
} 
