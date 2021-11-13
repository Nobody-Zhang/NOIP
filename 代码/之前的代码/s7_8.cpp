#include<bits/stdc++.h>
using namespace std;
int i[35],q,w;
void change(long long a,long long b)
{
	int q=0,e;
	while(e!=0)
	{
		w++;
		i[++q]=e=a%b;
		a=a/b;
	}
}
int main()
{
	long long m,n;
	//cin>>m>>n;
	scanf("%I64d%I64d",&m,&n);
	change(m,n);
	for(int y=w-1;y>=1;y--)
	 {
	  if(i[y]>=10) printf("%c",i[y]+55);
	  else  cout<<i[y];
	 }
	 return 0;
}
