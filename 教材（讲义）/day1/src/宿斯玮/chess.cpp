#include<bits/stdc++.h>
using namespace std;
#define inf 2333333 
#define R return  
int  fx[ 5 ] = { 0 , -1 , 0 , 1 , 0 } , fy[ 5 ] = { 0 , 0 , -1, 0, 1}; 
int  f[ 115 ][ 115 ] , mp[ 115 ][ 115 ] , m , n , ans = inf ;

void  dfs( int  x , int  y , int  sum , bool frog )
{
    if( x < 1 || y < 1 || x > m || y > m ) R ; 
    if( mp[ x ][ y ] == 0 ) R ;
    if( sum >= f[ x ][ y ] ) R ; 
    f[ x ][ y ] = sum ;
    if(x==m && y==m)
    {
        if(sum < ans) ans = sum; 
        R;
    }
    for(int i = 1 ; i <= 4; ++i)
    {
        int xx = x + fx[i];
        int yy = y + fy[i];
        if(mp[xx][yy]) 
        {
            if(mp[xx][yy] == mp[x][y]) 
                 dfs(xx, yy, sum, false); 
            else dfs(xx, yy, sum+1, false); 
        }   
        else 
        	if(!frog) 
        	{
        		mp[xx][yy] = mp[x][y];
        		dfs(xx, yy, sum+2, true); 
        		mp[xx][yy] = 0;
            }
    }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    memset(f, 0x3f3f3f, sizeof(f));
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= n; ++i)
    {
        int  m1 , m2 , m3 ;
        scanf("%d%d%d", &m1, &m2, &m3);
        mp[m1][m2] = m3 + 1;
    }
    dfs(1, 1, 0, false);
    printf("%d", ans==inf ? -1 : ans);
    R 0;
}