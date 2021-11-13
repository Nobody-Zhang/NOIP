#pragma GCC optimize(2) 
#include<bits/stdc++.h>
using namespace std;
struct s{
	int data;
	int len;
}a[1003];
int m,n;//[0]存数字，【1】存有多少位 
bool cmp(s s1,s s2)
{
	return s1.data<s2.data;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i].data);
		int mid=a[i].data;
		while(mid)
		{
			a[i].len++;
			mid/=10;
		}
	}
	sort(a+1,a+1+m,cmp);
	/*for(int i=1;i<=m;i++)
		cout<<a[i].data<<" "<<a[i].len<<endl;*/
	for(int i=1;i<=n;i++)
	{
		int ser,lon;
		scanf("%d%d",&lon,&ser);
		bool flag=false;
		for(int j=1;j<=m;j++)
		if(lon<=a[j].len)
		{
			int tmp1=ser,tmp2=a[j].data;
			bool fl=true;
			while(tmp1)
			{
				int las1=tmp1%10,las2=tmp2%10;
				tmp1/=10,tmp2/=10;
				if(las1!=las2){
					fl=false;
					break;
				}
			}
			if(fl){printf("%d\n",a[j].data);flag=true;break;}
		}
		if(!flag){printf("-1\n");}
	}
	return 0;
}
