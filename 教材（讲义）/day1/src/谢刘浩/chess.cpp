#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

inline void read(int &x){
    char s=getchar();x=0;
    while(s<'0'||s>'9')s=getchar();
    while(s>='0'&&s<='9')
    {x=(x<<1)+(x<<3)+s-'0';s=getchar();}
}
inline void print(int x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

int m,n,ans[102][102];
int h,l,c;
short map[102][102],mtof[102][102];
int dh[4]={-1,0,1,0},dl[4]={0,1,0,-1};

void dfs(int h,int l,bool tof,int qwq){
    if((h!=1||l!=1)&&qwq>=ans[h][l])return;
    ans[h][l]=qwq;
    if(h==m&&l==m)return;
    for(int i=0;i<=3;i++){
        int hh=h+dh[i],ll=l+dl[i];
        if(hh<=0||hh>m||ll<=0||ll>m)continue;
        if(mtof[hh][ll]==true||(map[hh][ll]==0&&tof==true))continue;
        mtof[hh][ll]=true;
        if(map[hh][ll]==0){
            map[hh][ll]=map[h][l];
            dfs(hh,ll,true,qwq+2);
            map[hh][ll]=0;
            mtof[hh][ll]=false;
            continue;
        }
        if(map[h][l]==map[hh][ll]){
            dfs(hh,ll,false,qwq);
            mtof[hh][ll]=false;
            continue;
        }
        dfs(hh,ll,false,qwq+1);
        mtof[hh][ll]=false;
    }
}

int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    read(m);read(n);
    while(n--){
        read(h);read(l);read(c);
        map[h][l]=c+1;
    }
    memset(ans,999999,sizeof(ans));ans[1][1]=0;
    dfs(1,1,false,0);
    if(ans[m][m]==999999||ans[m][m]==1061109567){putchar('-');putchar('1');return 0;}
    print(ans[m][m]);
    return 0;
}
