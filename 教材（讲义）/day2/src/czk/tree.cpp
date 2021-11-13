//tree
# include<bits/stdc++.h>
using namespace std;
int r[1000001],s[1000001][2];
int m=0,a;  
bool b=false; 
long long read()
{
    int x=0,f=1;
    char ch;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
inline void write(long long x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
void bfs(int x,int y){
    if(r[s[x][0]]==r[s[y][1]]&&r[s[x][1]]==r[s[y][0]]) {
        if(s[x][0]!=-1)                 
        {a+=2;bfs(s[x][0],s[y][1]);}    
        if(s[x][1]!=-1&&x!=y)           
        {a+=2;bfs(s[x][1],s[y][0]);}
    } 
    else b=true;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen ("tree.out","w",stdout);
    int i,n;cin>>n;
    for(i=1;i<=n;i++) 
	{
		r[i]=read();
	}
    for(i=1;i<=n;i++)
	{
		s[i][0]=read();s[i][1]=read();
	} 
    for(i=1;i<=n;i++){ 
        a=1,b=false;bfs(i,i);       
        if(b)continue;
        if(a>m)m=a;
    }
    write(m);    
    return  0;
}
/*
10
2 2 5 5 5 5 4 4 2 3
9 10
-1 -1
-1 -1
-1 -1
-1 -1
-1 2
3 4
5 6
-1 -1
7 8

3
*/
