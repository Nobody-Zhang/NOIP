#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
    char s[10];
    gets(s);
    int n=strlen(s);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        ans++;
        if(s[i]>='a'&&s[i]<='z')
        ans++;
        if(s[i]>='0'&&s[i]<='9')
        ans++;
    }
    printf("%d",ans);
    return 0;
}
