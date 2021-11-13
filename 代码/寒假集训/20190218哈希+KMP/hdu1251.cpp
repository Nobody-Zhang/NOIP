#include<bits/stdc++.h>
using namespace std;
#define maxn 10000005
char s[26];
int root,trie[maxn][26],cnt[maxn],ndnum;
void insert(char c[])
{
	int now=0;
	int len=strlen(c);
	for(int i=0;i<len;i++){
		int cp=c[i]-'a';
		if(trie[now][cp]==0){
			ndnum++;
			trie[now][cp]=ndnum;
		}
		now=trie[now][cp];
		cnt[now]++;
	}
}
int query(char c[])
{
	int now=0;
	for(int i=0;i<strlen(c);i++){
		int cp=c[i]-'a';
		if(!trie[now][cp]) return 0;
		now=trie[now][cp];
	}
	return cnt[now];
}
int main()
{
	while(gets(s)&&strcmp(s,"")!=0)
		insert(s);
	while(gets(s)) printf("%d\n",query(s));
} 
