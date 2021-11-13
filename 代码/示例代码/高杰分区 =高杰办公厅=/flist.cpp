#include<bits/stdc++.h>
using namespace std;
string s1,s2;
void calc(int l1,int r1,int l2,int r2)
{
    int i,j;
    for (i=l2;i<=r2;i++)
    {   int b=0;
        for (j=l1;j<=r1;j++)
            if (s2[i]==s1[j])
            {
                cout<<s1[j];
                b=1;    
                break;
            }
        if (b)
        break;
    }
    if (j>l1) calc(l1,j-1,1,r2);
    if (j<r1) calc(j+1,r1,1,r2);
}
int main()
{
    freopen("flist.in","r",stdin);
    freopen("flist.out","w",stdout);
    cin>>s1>>s2;
    calc(0,s1.length()-1,0,s2.length()-1);
    return 0;
}
 
