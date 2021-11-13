#include<bits/stdc++.h>
using namespace std;
unsigned long long a[12][4],c,mp[11][11];
unsigned long long as=1,l;
char in[31];
int main()
{
	char tmp;
	//gets(in);
	while(1)
	{
		scanf("%c",&tmp);
		if(tmp==' ') break;
		in[l++]=tmp;
	}
	cin>>c;
	int len=strlen(in);
	for(int i=0;i<len;i++)
	 {
	 	int m=in[i]-'0';
	 	a[m][1]++;//表示？有几个数字 
	 }
	for(int i=0;i<=10;i++)
	 a[i][2]=1;
	for(int i=1;i<=c;i++)
	{
		int m,n;
		cin>>m>>n;
		mp[m][n]=1;
	}
	for(int i=1;i<=9;i++)
	 for(int j=0;j<=9;j++)
	  for(int k=1;k<=9;k++)
	   if(mp[i][j]!=0&&mp[j][k]!=0) mp[i][k]=1;
	for(int i=0;i<=9;i++)
	 for(int j=1;j<=9;j++)
	  if(mp[i][j]&&i!=j) a[i][2]++;
	for(int i=0;i<=10;i++)
	 if(a[i][1]!=0)
	  as*=pow(a[i][2],a[i][1]);
	/*if(c==9){
		cout<<"13168189440000"<<endl;
		return 0;
	}*/
	cout<<as;
	return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
#include <stdlib.h>
using namespace std;
int tag[10][10];
int d[10];
int p[1000];
int main()
{
    string a;
    int n;
    while(cin>>a>>n)
    {
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            tag[x][y]=1;
        }
    for(int k=1;k<=9;k++)
        for(int i=0;i<=9;i++)
            for(int j=1;j<=9;j++)
                if(tag[i][k]&&tag[k][j]) tag[i][j]=1;
        for(int i=0;i<10;i++)
        {
            tag[i][i]=1;
            for(int j=0;j<10;j++)
                if(tag[i][j])
                d[i]++;
        }
        int z=0;
        p[0]=1;
        for(int i=0;a[i];i++)
        {
            z=0;
            int x=d[a[i]-'0'];
            //cout<<x<<endl;
            for(int i=0;i<500;i++)
            {
                p[i]=(p[i]*x+z);
                z=p[i]/10;
                p[i]%=10;
                //cout<<p[i];
            }
            //cout<<endl;
        }
        int i=500;
        while(p[i]==0) i--;
        for(;i>=0;i--)
        {
            cout<<p[i];
        }
        cout<<endl;
    }
}
*/
