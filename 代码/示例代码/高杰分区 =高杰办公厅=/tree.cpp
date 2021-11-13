#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n=-1;
void calc(int l2,int r)
{ 
	if(l2>r) return;
	n++;
	int m=s2.find(s1[n]);
	 calc(l2,m-1);
	  calc(m+1,r);
	cout<<s2[m];
}
int main(){
//	freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	cin>>s1>>s2;
	calc(0,s1.length()-1);//刚开始，从s1开头找，工作范围还未缩小 
	return 0;
}
