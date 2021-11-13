#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,tot,gg;
long long p1,s1,s2;
long long c[1000010];
struct node
{
	int weizhi;//当前的位置 
	long long chazhi;//气势的差值 
}s[1000010];
long long tiger,dragon;//龙虎双方气势 
long long starttiger,startdragon;//保存初始气势如果找不到最优解就放在m上 
bool cmp(node x,node y)//结构体排序就用来存最优值 
{
	return x.chazhi<y.chazhi;
}
int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cin>>m>>p1>>s1>>s2;//输入所需要的数据 
	for(int j=1;j<=m-1;j++)//龙方 
	{
		if(j==p1)
		{
			dragon+=(c[p1]+s1)*(m-p1);
			continue;
		}
		dragon+=c[j]*(m-j);
	} 
	for(int k=m+1;k<=n;k++)//虎方 
	{
		if(k==p1)
		{		
			tiger+=(c[p1]+s1)*(p1-m);
			continue;
		}
		tiger+=c[k]*(k-m);
	}//处理出龙方和虎方最初始的气势 
	starttiger=tiger;
	startdragon=dragon;
	if(startdragon==starttiger)
	{
		cout<<m;
		return 0;
	}//如果他们一开始就相等,那么怎么放也不可能有最好的值了,就索性放在m吧 
	if(dragon>tiger)//如果龙的气势比虎大时 
	{
		for(int i=m+1;i<=n;i++)//就在虎的阵营里面找 
		{
			tot++;//一个哨兵,避免重复加 
			tiger+=s2*(i-m);//加上当前受到影响的值 
			s[++cnt].chazhi=abs(dragon-tiger);//保存差值一定要用绝对值,有可能是负 
			s[cnt].weizhi=i;//保存编号 
			if(s[cnt].chazhi==0)//差值为零的话就直接把当前的编号输出,也满足最小(因为是按顺序找的) 
			{
				cout<<cnt;
				return 0;
			}
			if(tot==1)//又开始加下一个 
			{
				tot=0;//哨兵又清零 
				tiger-=s2*(i-m);//恢复之前的值 
				continue;
			}
	 	}
		sort(s+1,s+cnt+1,cmp);//结构体排序 
		if(abs(startdragon-starttiger)<s[1].chazhi)//如果一开始的差值绝对值比找到的最优值还小 
		{
			cout<<m;//就放在分隔点 
			return 0;
		}
		else
		{
			cout<<s[1].weizhi;//输出编号 
	 		return 0;
		}
	}
	if(dragon<tiger) 
	{
		for(int i=1;i<=m-1;i++)//在龙的阵营里面找
		{
			tot++;
			dragon+=s2*(m-i);
			s[++cnt].chazhi=abs(tiger-dragon);
			s[cnt].weizhi=i;
			if(s[cnt].chazhi==0)
			{
				cout<<cnt;
				return 0;
			}
			if(tot==1)
			{
				tot=0;
				dragon-=s2*(m-i);
				continue;
			}
		} 
		sort(s+1,s+cnt+1,cmp);
		if(starttiger-startdragon<s[1].chazhi)
		{
			cout<<m;
			return 0;
		}
		else
		{
			cout<<s[1].weizhi;
	 		return 0;
		}//思想同上面是一样的 
	}
	return 0; 
}
