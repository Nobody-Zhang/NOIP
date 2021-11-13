#include<bits/stdc++.h>
using namespace std;
int mp[2][7000],len1,len2;
char c[7000],s[7000];
inline int max(int a,int b){
	return a>b?a:b;
}
int main()
{
	freopen("lcs.in","r",stdin);
	freopen("lcs.out","w",stdout);
	scanf("%s",c);scanf("%s",s);
	len1=strlen(c);len2=strlen(s);
	for(int i=1;i<=len1;i++){
		int now=i&1,pre=now^1;
		for(int j=1;j<=len2;j++)
		{
			mp[now][j]=max(mp[pre][j],mp[now][j-1]);
			if(c[i]==s[j]){
				mp[now][j]=max(mp[now][j],mp[pre][j-1]+1);
			}
		}
	}
	printf("%d",mp[len1&1][len2]);
}
