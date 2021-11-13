#include<bits/stdc++.h>
using namespace std;
int m;
int t_1[10],t_2[10];
int time_1;
string in;
void main_in()
{
	
}
void f1()//时间复杂度为1 
{
	bool y;
	
}
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int j;
		cin>>j;
		char k;
		while(1)
		{
			cin>>k;
			if(k=='(') break;
		}
		int l=0;
		bool type_n=false;
		while(1)
		{
			char j;
			cin>>j;
			if(j==')') break;
			if(j<='9'&&j>='0') t_1[++t_1[0]]=j-'0';
			if(j=='n') type_n=true;
			if(type_n) t_1[++t_1[0]]=j-'0';
		}
		if(type_n)//含有字母n 
		f1();
		if(!type_n);//不含字母n
		//f2(); 
	}
 } 
