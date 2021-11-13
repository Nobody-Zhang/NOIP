#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,a[maxn],sta[maxn],p;//a储存每个的高度，sta相当于一个栈，p是它的数组模拟指针
int search1(int lef,int rig,int tar)
{//sta返回第一个小于tar的数的下标
//	if(lef==rig) return lef;
//	int mid=lef+(rig-lef)/2;
//	if(sta[mid]>tar) return search1(mid,rig,tar);
//	else return search1(lef,mid-1,tar);
	while(lef<rig)
	{
		int mid=lef+((rig-lef)>>1);//防止死循环
		if(sta[mid]>tar) lef=mid;
		else rig=mid-1;
//		else return mid;
	}
}
int search2(int lef,int rig,int tar)
{//返回第一个大于等于tar的数的下表
	if(lef==rig) return lef;
//	int mid=(lef+rig+1)/2;
	int mid=lef+(rig-lef)/2;
	if(sta[mid]>=mid) return search2(lef,mid,tar);
	else return search2(mid+1,rig,tar);
}
void speedup()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void in()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	n=1;//n是总共的个数
    while(cin>>a[n]) n++;
    n--;
}
int main()
{
	speedup();//加快输入
    in();//输入
    p=1;sta[p]=a[1];
    for(int i=2;i<=n;i++)
    {
    	if(a[i]<=sta[p]){
    		p++;
    		sta[p]=a[i];
		}
		else sta[search1(1,p,a[i])]=a[i];
	}
	cout<<p<<endl;
	memset(sta,0,sizeof(sta));
    p=1;sta[p]=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>sta[p]){
			p++;
			sta[p]=a[i];
		}
		else sta[search2(1,p,a[i])]=a[i];4
	}
	cout<<p<<endl;
	return 0;
}