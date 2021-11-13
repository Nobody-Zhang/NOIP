#include<bits/stdc++.h>
using namespace std;
int m,n;
long long in[100010],tmp[100010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;//n个数字，m段
	long long tot=0;
	for(int i=1;i<=n;i++)
	{
		cin>>in[i];
		tmp[i]=in[i];
		tot+=in[i];
		//sum[i]=sum[i-1]+in[i];//计算前缀和
	}
	sort(tmp+1,tmp+1+n);
	long long lef=tmp[n],rig=tot;
	while(1)
	{
		long long mid=(lef+rig)/2;
		long long sum=0;
		if(lef==mid)
		{
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				sum+=in[i];
				if(sum>rig){
					flag++;
					sum=in[i];
				}
			}
			flag++;
			if(flag==m) cout<<rig<<endl;
			else cout<<lef<<endl;
			return 0;
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			sum+=in[i];
			if(sum>mid){
				flag++;
				sum=in[i];
			}
		}
		flag++;
		if(flag>m) lef=mid+1; //说明mid定小了
		else rig=mid;
	}
	
	/*for(int i=1;i<=n;i++)
	{
		if(in[n]<=sum[i]){
			lef=sum[i];
			break;
		}
	}
	
	long long lef=in[n],rig=sum[n];
	while(1)
	{
		//写判断条件
 		long long mid=(lef+rig)/2;
		if(lef==mid)
		{
			if(sum[n]/rig==m-1) cout<<rig<<endl;
			else cout<<lef<<endl;
			return 0;
			while(sum[n]/rig==m-1){
				rig++;
			}
			cout<<rig-1<<endl;
			return 0;
		}
		int tot=0;//与m比大小
		if(sum[n]/mid>m-1) lef=mid+1;
		else rig=mid;
	}*/
}