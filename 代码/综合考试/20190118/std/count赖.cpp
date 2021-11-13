#pragma G++ optimize (2)
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define input(x) freopen(x,"r",stdin)
#define output(x) freopen(x,"w",stdout)

int pos[15]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
string num;

long long to_num(string s)
{
	long long ret=0;
	
	for(int i=0;i<(int)s.length();i++) ret=ret*10+s[i]-'0';
	
	return ret;
}

string to_str(long long x)
{
	int p=0;
	string ret;
	
	while(x)
	{
		ret.push_back((char)(x%10+'0'));
		x/=10;
	}
	reverse(ret.begin(),ret.end());
	
	return ret;
}

int main()
{
	input("count.in");
	output("count.out");
	long long n;
	
	scanf("%I64d",&n);
	
	num=to_str(n);
	
	for(int i=0;i<=9;i++)
	{
		long long ans=0;
		
		if(num[0]-'0'>i&&i) ans+=pos[num.length()];
		else if(num[0]-'0'==i&&i)
		{
			string tmp;
			string::iterator it;
			
			it=num.begin();
			advance(it,1);
			tmp.assign(it,num.end());
			ans+=(to_num(tmp)+1);
		}
		for(int j=1;j<num.length();j++)
		{
			if(num[j]-'0'>i)
			{
				string tmp;
				
				tmp.assign(num,0,j);
				ans+=((to_num(tmp)+1)*pos[num.length()-j]);
			}
			else if(num[j]-'0'==i)
			{
				string tmp1,tmp2;
				string::iterator it;
				
				tmp1.assign(num,0,j);
				it=num.begin();
				advance(it,j+1);
				tmp2.assign(it,num.end());
				ans+=((to_num(tmp1)*pos[num.length()-j])+to_num(tmp2)+1);
			}
			else
			{
				string tmp;
				
				tmp.assign(num,0,j);
				ans+=(to_num(tmp)*pos[num.length()-j]);
			}
		}
		if(!i)
		{
			string tmp;
			
			tmp.assign(num.length()-1,'1');
			ans-=(to_num(tmp));
		}
		
		printf("%I64d\n",ans);
	}
	
	return 0;
}
