#include<bits/stdc++.h>
using namespace std;
int m,n,in[1010],len,point;
int main()
{
	freopen("train.in","r",stdin);
	freopen("train.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		if(k>point)
		{
			for(int j=point+1;j<=k;j++)
			 in[++len]=j;
			point=k;
		}
		if(k<=point) 
		{
			if(in[len]==k) len--;
			else {
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
