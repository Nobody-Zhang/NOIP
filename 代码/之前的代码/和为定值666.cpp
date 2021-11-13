#include<bits/stdc++.h>
using namespace std;
int a[100005];
int i,l,mid,as,o;
int search(int min,int max,int n)
{
	mid=(min+max)/2;
	if(min>max)
	return 0;
	if(n==a[mid]) return mid;
	else if(n>a[mid]) return search(mid+1,max,n);
	else return search(min,mid-1,n);
}
int main()
{
	cin>>i;
	for(int u=1;u<=i;u++)
	 cin>>a[u];
	sort(a+1,a+i+1);
	cin>>l;
	for(int k=1;k<=i;k++)
	 {
	 	as=search(k+1,i,l-a[k]);
		if(as!=0)
		{
			cout<<a[k]<<" "<<a[as];
			break;
		}
	 }
	 if(as==0) cout<<"No";
	return 0;
}
