#include<bits/stdc++.h>
using namespace std;
string s1,s2;
void clic(int l1,int r1,int l2,int r2)
{
	int m=s2.find(s1[l1]);
	if(m>l2) clic(l1+1,l1+m,l2,m-1);
	if(m<r2) clic(l1+m-l2+1,r1,m+1,r2);
	cout<<s1[l1];
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>s1>>s2;
	clic(0,s1.length()-1,0,s2.length()-1);
	cout<<endl; 
}
