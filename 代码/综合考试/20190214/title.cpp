#include<bits/stdc++.h>
using namespace std;
int tot;
char c[101];
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	gets(c);
	//int len=c.length();
	for(int i=0;i<=5;i++)
	{
		if(c[i]!=' '&&c[i]!='\000')tot++;
	}
	/*for(int i=0;i<=5;i++)
	 cout<<c[i];
	cout<<endl;*/
	cout<<tot<<endl;
	return 0;
}
