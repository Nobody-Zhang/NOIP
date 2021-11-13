#include<bits/stdc++.h>
using namespace std;
const  long long  N =  2000012 ;
inline long long read()
{
    long long s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}
long long  n , k , a[ N ] , loc[ N ], q[ N ] ;
long long  dp[ N ] , sum[ N ] ;

int main()
{
    freopen("group.in","r",stdin);
    freopen("group.out","w",stdout);
    n = read() , k = read() ;
    for(long long i = 1;i <= n ; i++ ){
        a[ i ] = read() ;
        sum[ i ] = sum[ i - 1 ] + a[ i ] ;
    }
    for( long long  i = 1 ; i <= k ; i++ )dp[ i ] = sum[ i ] ;//初值
    long long  head = 1 , tail = 0 ;
    for( long long i = 1 ; i <= n ; i++ )
    {

        while( head <= tail && i - loc[ head ] > k + 1 ) head++ ; //队不为空 且 队首太远 出队
        if( i > k ){
            dp[ i ] = q[head] + sum[ i ] ;
        }//更新DP

        while( head <= tail && dp[ i ] - sum[ i + 1 ] >= q[ tail ]) tail-- ; // 队不为空 且 队末不符合单调
        q[ ++tail ] = dp[ i ] - sum[ i + 1 ] ; loc[ tail ] = i ; //将新元素入队
        
        //if( i - k >= 0) prlong longf("%d\n" , q[head]); //符合输出
    }
    long long  ans = 0 ;
    for( long long  i = 1 ; i <= n ; i++ ){
        ans = max( ans , dp[ i ] ) ;
    }
    cout<<ans ;
    return 0;
}