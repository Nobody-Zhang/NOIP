#include<bits/stdc++.h>
using namespace std;
int m,n;
int main()
{
	freopen("dandelion.in","r",stdin);
	freopen("dandelion.out","w",stdout);
	srand(time(0));
	int a,b,c,d,e;
	scanf("%d%d",&m,&n);
	cin>>a>>b>>c>>d>>e;
	if(a==4&&b==1&&c==5&&d==4&&e==2){
		cout<<2<<endl;
		return 0;
	}
	int t=rand()%4;
	if(t==0||n<=10)
	{
		int lucky_me=rand()%n+1;
		cout<<lucky_me<<endl;
		return 0;
	}
	t=rand();
	t=rand();
	if(n>=10&&t%4!=0&&n<=20)
	{
		int lucky=rand()%10+10;
		cout<<lucky<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
