#include<bits/stdc++.h>
using namespace std;
int a[25],used[25],r,n,total;
void search(int s)
{
	if(s==r+1) 
	{
		for(int o=1;o<=r;o++)
		 printf("%d ",a[o]);
		cout<<"\n";
		total++;
	}
	for(int i=1;i<=n;i++)
	 	if(used[i]==0)
	 	{
	 		a[s]=i;
	 		used[i]=1;
	 		search(s+1);
	 		used[i]=0;
	 	}
} 
int main()
{
	cin>>n>>r;
	search(1);
	cout<<total;
	return 0;
}
