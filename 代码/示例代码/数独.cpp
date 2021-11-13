#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define rp(x,y) (x)*9+y+81
#define cp(x,y) (x)*9+y+162
#define pp(x,y) (x)*9+y+243
const int N = 60003;
const int INF = 0x7fffffff;
int u[N],d[N],L[N],R[N];
int X[N],C[N],s[1003],h[1003],tot,id,ans[103];
bool mark[1003];
struct data {
    int pos,val;
}a[1003],q[103];
inline void del(int c) {
    L[R[c]] = L[c] ; R[L[c]] = R[c];
    for(int i = d[c] ; i != c ; i = d[i])
        for(int j = R[i] ; j != i ; j = R[j])
            d[u[j]] = d[j] , u[d[j]] = u[j] , s[C[j]]--;
}
inline void add(int c) {    
    L[R[c]] = R[L[c]] = c;
    for(int i = u[c] ; i != c ; i = u[i])
        for(int j = L[i] ; j != i ; j = L[j])
            d[u[j]] = u[d[j]] = j , s[C[j]]++;
}
inline void link(int r,int c) {
    s[c]++ ; C[++tot] = c ; X[tot] = r;
    u[tot] = c ; d[tot] = d[c];
    u[d[tot]] = tot ; d[u[tot]] = tot;
    if(h[r]==-1) {
        h[r] = L[tot] = R[tot] = tot;
    } else {
        L[tot] = h[r] ; R[tot] = R[h[r]];
        L[R[tot]] = tot ; R[L[tot]] = tot;
    }
}
inline bool dance(int k) {
    if(R[0]==0) {
        for(int i = 1 ; i <= 81 ; ++i) ans[q[i].pos] = q[i].val;
        for(int i = 1 ; i <= 81 ; ++i) printf("%d",ans[i]);
        printf("\n");
        return 1;
    }
    int temp = INF , c = R[0];
    for(int i = R[0] ; i ; i = R[i])
        if(s[i] < temp) temp = s[i] , c = i;
    del(c);
    for(int i = d[c] ; i != c ; i = d[i]) {
        q[k+1] = a[X[i]];
        for(int j = R[i] ; j != i ; j = R[j]) del(C[j]);
        if(dance(k+1)) return 1;
        for(int j = L[i] ; j != i ; j = L[j]) add(C[j]);
    }
    add(c);
    return 0;
}
char ch[203];
int main() {
    while(scanf("%s",ch+1)) {
        if(ch[1]=='e') return 0;
        id = tot = 0;
        memset(h,-1,sizeof(h));
        memset(mark,0,sizeof(mark));
        for(int i = 0 ; i <= 4*81 ; ++i) {
            R[i] = i + 1 ; L[i+1] = i;
            u[i] = d[i] = i;
            s[i] = 0;
        }
        L[0] = 4*81 ; R[4*81] = 0 ; tot = 4*81;
        for(int i = 0 ; i < 9 ; ++i) 
            for(int j = 0 ; j < 9 ; ++j)
                if(ch[i*9+j+1]!='.') {
                    int t = ch[i*9+j+1]-'0' , p = i/3*3+j/3;
                    mark[rp(i,t)] = mark[cp(j,t)] = mark[pp(p,t)] = 1;
                }
        for(int i = 0 ; i < 9 ; ++i)
            for(int j = 0 ; j < 9 ; ++j) {
                int t = ch[i*9+j+1]!='.'?ch[i*9+j+1]-'0':0;
                int p = i/3*3+j/3;
                if(t) {
                    id++ ; a[id].pos = i*9+j+1 ; a[id].val = t;
                    link(id,i*9+j+1);
                    link(id,rp(i,t));
                    link(id,cp(j,t));
                    link(id,pp(p,t));
                } else {
                    for(int k = 1 ; k <= 9 ; ++k) {
                        if(!mark[rp(i,k)]&&!mark[cp(j,k)]&&!mark[pp(p,k)]) {
                            id++ ; a[id].pos = i*9+j+1 ; a[id].val = k;
                            link(id,i*9+j+1);
                            link(id,rp(i,k));
                            link(id,cp(j,k));
                            link(id,pp(p,k));
                        }
                    }
                }
            }
        dance(0);
    }
}
