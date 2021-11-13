#include<bits/stdc++.h>
using namespace std;
string s;
int len,in[10],ans[10];
int ask(int po)
{
	int point=0;
	for(int i=1;i<po;i++)
	 point=point*10+in[i];
	return point;
}
int ask1(int po)
{
	int out=0;
	for(int i=po+1;i<=len;i++)
	 out=out*10+in[i];
	return out;
}

int power(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = (long long)ans * a;
		a = (long long)a * a;
	}
	return ans;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>s;
	len=s.length();
	for(int i=1;i<=len;i++)
	 in[i]=s[i-1]-'0';
	 
//	 for(int i=1;i<=len;i++) cout<<in[i]<<' ';
//	 cout<<endl<<ask(3)<<' '<<ask1(3);
	 
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(j<in[i]){
				ans[j]=ans[j]+(ask(i)+1)*power(10,(len-i));
			}
			else if(j==in[i]){
				ans[j]=ans[j]+ask(i)*power(10,(len-i))+ask1(i)+1;
			}
			else if(j>in[i]){
				ans[j]=ans[j]+(ask(i))*power(10,(len-i));
			}
		}
	}
	int out=1,inc=2;
	while(inc<=len)
	{
		out*=10;
		out+=1;
		inc++;
	}
	ans[0]-=out;
	for(int i=0;i<=9;i++)
	 cout<<ans[i]<<endl;
	return 0;
}
