#include<bits/stdc++.h>
using namespace std;
char in[2500*25+1];
int t;//储存长度
int win[2500*25+1][3],tot;
int main()
{
	bool flag=false;
	while(1)
	{
		string s;
		cin>>s;
		int len=s.length();
		for(int i=0;i<len;i++)
		{
			int j=t;
			if(s[i]=='E') {
				flag=true;//已经输入完毕
				break;
			}
			j++;
			in[j]=s[i];
			t++;
		}
		if(flag) break;
	}
	/*for(int i=1;i<=t;i++)
		cout<<in[i];
	*/
	tot=1;
	for(int i=1;i<=t;i++)
	{
		if(in[i]=='W') win[tot][1]++;
		if(in[i]=='L') win[tot][2]++; 
		if(win[tot][1]>=11||win[tot][2]>=11)
		{
			if(abs(win[tot][1]-win[tot][2])>=2) tot++;
		}
	}
	for(int i=1;i<=tot;i++)
		cout<<win[i][1]<<":"<<win[i][2]<<endl;
	memset(win,0,sizeof(win));
	tot=1;
	cout<<endl;
	for(int i=1;i<=t;i++)
	{
		if(in[i]=='W') win[tot][1]++;
		if(in[i]=='L') win[tot][2]++; 
		if(win[tot][1]>=21||win[tot][2]>=21)
		{
			if(abs(win[tot][1]-win[tot][2])>=2) tot++;
		}
	}
	for(int i=1;i<=tot;i++)
		cout<<win[i][1]<<":"<<win[i][2]<<endl;
	return 0;
}