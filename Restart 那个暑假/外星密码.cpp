#include<bits/stdc++.h>
using namespace std;
int len,loc[1000000][3],fg[2000000],lst[2000000];//len是长度
string s;
void print(int flag,int th)
{//flag是当前指针指到现在的[，th是现在打印第几个括号
	flag++;
	int t=0;
	while(s[flag]<='9'&&s[flag]>='0'){
		t=t*10+s[flag]-'0';
		flag++;
	}//flag现在到了第一个字母
	for(int i=1;i<=t;i++)
	{
		int temp=th;
		for(int j=flag;j<loc[th][2];)
		{
			if(s[j]=='['){
				temp++;
				print(j,temp);
				j=loc[temp][2]+1;
				continue;//这样就永远不会到]的地方
			}
			cout<<s[j];
			j++;
		}
	}
}
int main()
{
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='[') {
			loc[0][1]++;//代表左括号的个数
			loc[loc[0][1]][1]=i;
			lst[0]++;
			lst[lst[0]]=loc[0][1];
		}
		if(s[i]==']'){
			loc[0][2]++;
			loc[lst[lst[0]]][2]=i;
			lst[0]--;
		}
	}
	memset(lst,0,sizeof(lst));
	int total=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='['){
			total++;
			lst[i]=total;
		}
	}
	int i=0;
	for(;;i++)
	{
		if(i==len) return 0;
		if(s[i]=='[') break;
		cout<<s[i];//最开始的输出
	}
	//for(int j=1;j<=loc[0][1];j++)
//		if(loc[j][2]==0) search(j,loc[j][1]+1);
//	print(i,1);
	while(i!=len){
		if(s[i]=='[') {
			print(i,lst[i]);
			i=loc[lst[i]][2]+1;
			continue;
		}
		cout<<s[i];
		i++;
	}
//	for(int j=1;j<=loc[0][1];j++)
//	cout<<loc[j][1]<<"  "<<loc[j][2]<<endl;
	return 0;
}