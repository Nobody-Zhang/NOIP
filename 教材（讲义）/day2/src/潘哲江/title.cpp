#include<bits/stdc++.h>
using namespace std;
int ans;
string s;
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
    while(cin>>s) 
    {
        for(int i=0;i<=s.size();i++) 
        {
            if(s[i]>='a' && s[i]<='z') 
			{
			ans++;
			continue;
			}
            if(s[i]>='A' && s[i]<='Z') 
			{
			ans++;
			continue;
			}
            if(s[i]>='0' && s[i]<='9') 
			ans++;
        }
    }
    cout<<ans;
    return 0;
}
