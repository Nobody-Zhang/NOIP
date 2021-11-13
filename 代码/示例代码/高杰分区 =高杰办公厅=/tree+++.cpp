#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n=-1;
void calc(int l2,int r){//l1是s1找的起点，l2和r共同限制了工作的区域 
    if(l2>r) return;
	n++;
	int m=s2.find(s1[n]);//第一次遍历找到根节点 
	calc(l2,m-1);//找左子树（r=m-1），从根节点左边找 
	calc(m+1,r);
	cout<<s2[m];
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	cin>>s1>>s2;
	calc(0,s2.length()-1);//刚开始，从s1开头找，工作范围还未缩小 
	return 0;
}
