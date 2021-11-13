#include<bits/stdc++.h>
using namespace std;
string s1,s2;
struct tree1
{
	char data;
	int lchi,rchi;
	tree1(){
		data='\000';
		lchi=rchi=-1;
	}
};
struct tree1 t[35];
int root;
void bd_tree(int m,int n)
{
	for(int i=m;i<=n;i++)
	{
		if(s1[root]==s2[i])
		{
			int x=root;
			t[x].data=s2[x];
			root++;
			if(i-1>=m)
			 {
				t[x].lchi=root;
			 	bd_tree(m,i-1);
			 }
			if(i+1<=n)
			 {
			 	t[x].rchi=root;
			 	bd_tree(i+1,n);
			 }
			return;
		}
	}
}
void print_tree(int m)
{
	if(t[i].lchi!=-1)
	 cout<<
}
int main()
{
	cin>>s1>>s2;
	bd_tree(0,s1.length()-1);
	print_tree(0);
}
