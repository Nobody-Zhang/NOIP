#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int a[1000+10],b;

int main()
{
    int n,m,l,f;
    freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
	scanf("%d",a+i);
    sort(a+1,a+n+1);
    while(m--)
    {
        f=-1;
        scanf("%d %d",&l,&b);
        int w = pow(10,l);
        for(int i=1;i<=n;i++)
            if(a[i]%w == b)
            {
               f=a[i];
               break;
            }
        printf("%d\n",f);
    }
}
