#include<bits/stdc++.h>
using namespace std;
string s;
int a[2001],b[2001],ans[4001],lena,lenb;
int mid[2001][4001];
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	lena=s.length();
	if(s=="0"){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<lena;i++)
		a[lena-i]=s[i]-48;//逆向存储一遍
	cin>>s;
	lenb=s.length();
	if(s=="0"){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<lenb;i++)
		b[lenb-i]=s[i]-48;//字符转化成数字
	for(int i=1;i<=lena;i++)
	{
		for(int j=1;j<=lenb;j++)
		{
			mid[i][j+i-1]+=a[i]*b[j];
			if(mid[i][j+i-1]>=10){
				mid[i][i+j]+=(mid[i][j+i-1]/10);
				mid[i][j+i-1]=mid[i][j+i-1]%10;
			}
		}
	}
	/*for(int i=1;i<=lena;i++)
	{
		for(int j=1;j<=lena+lenb;j++)
		 cout<<mid[i][j];
		cout<<endl;
	}
	*/
	for(int i=1;i<=lena;i++)
		for(int j=1;j<=lena+lenb;j++){	
			ans[j]+=mid[i][j];
	}
	for(int i=1;i<=lena+lenb+1;i++)
		if(ans[i]>=10)
		{
			ans[i+1]+=(ans[i]/10);
			ans[i]%=10;
		}
	int flag=4000;
	while(ans[flag]==0){
		flag--;
	}
	for(int i=flag;i>=1;i--)
		cout<<ans[i];
	return 0;
}