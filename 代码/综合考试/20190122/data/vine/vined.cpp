#include<cstdio>
#include<cstdlib>
void work0(int n){
    printf("%d %d\n",n,1);
    printf("%d %d\n",0,rand()%n+1);
}
void work1(int n,int m){
    printf("%d %d\n",n,m);
    int a,b;
    for(int i=1;i<=m;++i){
        a=b=0;
        while(a==b)a=rand()%(n+1),b=rand()%(n+1);
        printf("%d %d\n",a,b);
    }
}
void work2(int n,int m){
    printf("%d %d\n",n,m);
    int a,b;
    for(int i=1;i<=m;++i){
        a=b=0;
        while(a==b)a=rand()%n+1,b=rand()%n+1;
        printf("%d %d\n",a,b);
    }
}
void work3(int n,int m){
    printf("%d %d\n",n,m);
    int a,b;
    printf("%d %d\n",0,rand()%n+1);m--;
    while(m>0&&rand()%2==1){
        printf("%d %d\n",0,rand()%n+1);m--;
    }
    for(int i=1;i<=m;++i){
        a=b=0;
        while(a==b)a=rand()%(n+1),b=rand()%(n+1);
        printf("%d %d\n",a,b);
    }
}
void work4(int n,int m,int typ){
    printf("%d %d\n",n,m);
    for(int i=2;i<n;++i){
        printf("%d %d\n",i,rand()%(i-1)+1);m--;
    }
    if(typ){
        do{
            printf("%d %d\n",0,rand()%n+1);m--;
        }while(m>0&&rand()%2==1);
    }
    int a,b;
    for(int i=1;i<=m;++i){
        a=b=0;
        while(a==b)a=rand()%n+1,b=rand()%n+1;
        printf("%d %d\n",a,b);
    }
}
void work5(int n,int m){
    printf("%d %d\n",n,m);
    for(int i=2;i<=n;++i){
        printf("%d %d\n",i,rand()%(i-1)+1);m--;
    int a,b;
    for(int i=1;i<=m;++i){
    }
        a=b=0;
        while(a==b)a=rand()%(n+1),b=rand()%(n+1);
        printf("%d %d\n",a,b);
    }
}
int main(){
    srand((unsigned long long)(new char));
    int T=100;
    printf("%d\n",T);  
    work3(30000,200000);
    work4(10000,100000,0);T--;T--;
    while(T--){
        work3(T*12,rand()%100+T*(rand()%20)+T*12);   
    }
    return 0;
}