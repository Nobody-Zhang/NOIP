#include<bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;
int fx[4]={-1,0,1,0}; 
int fy[4]={0,-1,0,1}; 
int f[110][110]; 
int mp[110][110]; 
int m,n,ans=inf;
void dfs(int x,int y,int sum,bool frog){
    if(x<1||y< 1||x>m||y > m) return;
    if(mp[x][y]==0) return; 
    if(sum>=f[x][y]) return;
    f[x][y]=sum;
    if(x==m&&y==m) {
        if(sum<ans)ans=sum;
        return;
    }
    for(int i=0;i<4;++i){
        int xx = x + fx[i];
        int yy = y + fy[i];
        if(mp[xx][yy]) {
            if(mp[xx][yy] == mp[x][y]) 
                 dfs(xx, yy, sum, false); 
            else dfs(xx, yy, sum+1, false); 
        }  
		else {
        if(!frog) {
            mp[xx][yy]=mp[x][y];
            dfs(xx,yy,sum+2,true); 
            mp[xx][yy]=0;
        }
		}
    }
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    memset(f,0x7f,sizeof(f));
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;++i){
        int x,y,c;
       cin>>x>>y>>c;
        mp[x][y] = c + 1;
    }
    dfs(1,1,0,0);
    if(ans==inf)cout<<"-1\n";
    else cout<<ans<<endl;
    return 0;
}
