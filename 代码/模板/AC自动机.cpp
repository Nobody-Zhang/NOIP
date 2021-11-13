#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[60];
const int MAX=1000000+10;
char b[MAX];
struct Node{
	int num;
	Node *next[26],*fail;
	Node(){
		num=0;
		memset(next,0,sizeof(next));
		fail=NULL;
	}
}*root;
queue<Node*>q;
void init(char *a)
{
	Node *p=root;
	int k=0;
	while(a[k]){
		if(!p->next[a[k]-'a']) p->next[a[k]-'a']=new Node;
		p=p->next[a[k]-'a'];
		k++;
	}
	p->num++;
}
void build()
{
	Node *p=root,*next;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(p->next[i]){
				next=p->fail;
				while(next){
					if(next->next[i]){
						p->next[i]->fail=next->next[i];
						break;
					}
					next=next->fail;
				}
				if(!next) p->next[i]->fail=root;
				q.push(p->next[i]);
			}
		}
	}
	return;
}
int search(char *a)
{
	int k=0,num=0;
	Node *p=root,*next;
	while(a[k])
	{
		while(!p->next[a[k]-'a']&&p!=root) p=p->fail;
		p=p->next[a[k++]-'a'];
		if(!p) p=root;
		next=p;
		while(next!=root&&next->num!=-1){
			num+=next->num;
			next->num=-1;
			next=next->fail;
		}
	}
	return num;
}
void del(Node *p)
{
	for(int i=0;i<26;i++) if(p->next[i]) del(p->next[i]);
	delete p;
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		root=new Node;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
            scanf("%s",a);
			init(a);
		}
		build();
		scanf("%s",b);
		printf("%d\n",search(b));
		del(root);
	}
	return 0;
}
