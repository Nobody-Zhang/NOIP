#include<bits/stdc++.h>
using namespace std;
string a[10001];
int m,tot;
int main()
{
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	while(cin>>a[++m]);
	m--;
	sort(a+1,a+m+1);
	tot=a[1].length();
	for(int i=2;i<=m;i++)
	{
		int tmp=0;
		while(a[i][tmp]==a[i-1][tmp]&&tmp<a[i-1].length())
		 tmp++;
		tot+=a[i].length()-tmp;
	}
	cout<<tot+1<<endl;
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
struct tree1()
{
	char data;
	char *lson,*rson;
	tree(){
		lson=rson=NULL;
		data='\000';
	}
};
struct tree1 *root,dz[1001];
int t
void creat_tree(tree1 *&bt)
{
	char x;
	scanf("%c",x);
	if(x!='\n')
	{
		bt=dz[++t];
		bt->data=x;
		creat_tree
	}
}
int main()
{
	creat_tree(root);
}*/
