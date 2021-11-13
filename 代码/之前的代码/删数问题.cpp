#include<bits/stdc++.h>
using namespace std;
int n[251],s;
char in[251];
bool flag=false;
int lenth;
/*void lon()
{
    for(lenth=1;lenth<=241;lenth++)
     if(n[lenth]=='0') 
     {
     	lenth--;
         return;
     }
}*/
int main()
{
    string strl;
    gets(in);
     cin>>s;
    lenth=strlen(in);
    for(int i=0;i<lenth;i++)
     {
     	n[i+1]=in[i]-'0';
     }
    //lon();
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=lenth-1;j++)
         if(n[j]>n[j+1])
         {
         	for(int k=j;k<=lenth-1;k++)
         	 n[k]=n[k+1];
         	break;
         }
         lenth--;
    }
    for(int i=1;i<=lenth;i++)
    {
        if(n[i]!=0) flag=true;
        if(flag) cout<<n[i];
    }
    return 0;
}
