#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,tot,gg;
long long p1,s1,s2;
long long c[1000010];
struct node
{
	int weizhi;//��ǰ��λ�� 
	long long chazhi;//���ƵĲ�ֵ 
}s[1000010];
long long tiger,dragon;//����˫������ 
long long starttiger,startdragon;//�����ʼ��������Ҳ������Ž�ͷ���m�� 
bool cmp(node x,node y)//�ṹ�����������������ֵ 
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
	cin>>m>>p1>>s1>>s2;//��������Ҫ������ 
	for(int j=1;j<=m-1;j++)//���� 
	{
		if(j==p1)
		{
			dragon+=(c[p1]+s1)*(m-p1);
			continue;
		}
		dragon+=c[j]*(m-j);
	} 
	for(int k=m+1;k<=n;k++)//���� 
	{
		if(k==p1)
		{		
			tiger+=(c[p1]+s1)*(p1-m);
			continue;
		}
		tiger+=c[k]*(k-m);
	}//����������ͻ������ʼ������ 
	starttiger=tiger;
	startdragon=dragon;
	if(startdragon==starttiger)
	{
		cout<<m;
		return 0;
	}//�������һ��ʼ�����,��ô��ô��Ҳ����������õ�ֵ��,�����Է���m�� 
	if(dragon>tiger)//����������ƱȻ���ʱ 
	{
		for(int i=m+1;i<=n;i++)//���ڻ�����Ӫ������ 
		{
			tot++;//һ���ڱ�,�����ظ��� 
			tiger+=s2*(i-m);//���ϵ�ǰ�ܵ�Ӱ���ֵ 
			s[++cnt].chazhi=abs(dragon-tiger);//�����ֵһ��Ҫ�þ���ֵ,�п����Ǹ� 
			s[cnt].weizhi=i;//������ 
			if(s[cnt].chazhi==0)//��ֵΪ��Ļ���ֱ�Ӱѵ�ǰ�ı�����,Ҳ������С(��Ϊ�ǰ�˳���ҵ�) 
			{
				cout<<cnt;
				return 0;
			}
			if(tot==1)//�ֿ�ʼ����һ�� 
			{
				tot=0;//�ڱ������� 
				tiger-=s2*(i-m);//�ָ�֮ǰ��ֵ 
				continue;
			}
	 	}
		sort(s+1,s+cnt+1,cmp);//�ṹ������ 
		if(abs(startdragon-starttiger)<s[1].chazhi)//���һ��ʼ�Ĳ�ֵ����ֵ���ҵ�������ֵ��С 
		{
			cout<<m;//�ͷ��ڷָ��� 
			return 0;
		}
		else
		{
			cout<<s[1].weizhi;//������ 
	 		return 0;
		}
	}
	if(dragon<tiger) 
	{
		for(int i=1;i<=m-1;i++)//��������Ӫ������
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
		}//˼��ͬ������һ���� 
	}
	return 0; 
}
