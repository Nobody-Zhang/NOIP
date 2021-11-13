#include<bits/stdc++.h>
using namespace std;
char in[1001];
int pp,head;
int main()
{
	gets(in);
	int len=strlen(in);
	for(int i=len-1;i>=0;i--)
	 in[i+1]=in[i];
	for(int i=1;i<=len-1;i++)
	 search(in[i],in[i+1]);
	if(pp!=0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
}
