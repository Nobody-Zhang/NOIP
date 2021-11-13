#include<bits/stdc++.h>
using namespace std;
/*template <typename T>inline void redi(T& t)
{
    register int c=getchar();
    t=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) t=t*10+c-'0',c=getchar();
}
template <typename T,typename...Args>inline void redi(T& t,Args&... args)
{
    redi(t);
    redi(args...);
}*/
struct sec{
    int mid[10],pos,step;
    /*sec(){
        memset(mid,0,sizeof(mid));
        pos=step=0;
    }///*/
};
int in[100],goal[100]={0,1,2,3,8,0,4,7,6,5};
int run[]={0,1,-1,3,-3};
int m1[362881],m2[362881];
//map<int,int>m1,m2;
queue<sec> qfr,qen;
//bool mapp1[20],mapp2[20];
int kd(int mp[10])
{//康德展开 
    int ans=0;
    for(int i=1;i<=9;i++)
     {
     	int inc=0,mid=1;
     	for(int j=i;j<=9;j++)
     	{
     		if(mp[i]>mp[j]) inc++;
     	}
     	for(int j=9-i;j>=1;j--)
     	 mid*=j;
     	mid*=inc;
     	ans+=mid;
     }
     return ans;
}
/*const int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320,362880};///阶乘  
int kd(int s[])  
{  
    int n=8;
    int i, j, cnt, sum;  
    sum = 0;  
    for (i = 0; i < n; ++i)  
    {  
        cnt = 0;  
        for (j = i + 1; j < n; ++j)  
            if (s[j] < s[i]) ++cnt;  
        sum += cnt * fac[n - i - 1];  
    }  
    return sum;  
}*/
/*int kd(int s[])
{
    int ans=0;
    for(int i=9;i>=1;i--)
     {
     	ans=ans*10;
     	ans+=s[i];
     }
     return ans;
}
int kd(int mp[10])
{
    int ans=0;
    for(int i=1;i<=9;i++)
     {
     	int inc=0,mid=1;
     	for(int j=i;j<=9;j++)
     	{
     		if(mp[i]>mp[j]) inc++;
     	}
     	for(int j=i;j>=i;j--)
     	 mid*=j;
     	mid*=inc;
     	ans+=mid;
     }
     return ans;
}*/
/*void judge(int tot)
{
    if(m2[kd()]!=0)
    {
        cout<<m[kd()]+tot-1<<endl;
        exit(0);
    }
    if(m1[kd()]!=0)
    {
        cout<<m[kd()]+tot-1<<endl;
        exit(0);
    }
}*/
void print(int a,int b)
{
    cout<<a+b<<endl;
/*	for(int j=1;j<=3;j++)
                   cout<<qen.front().mid[j]<<" ";
                    cout<<endl;
                   for(int j=4;j<=6;j++)
                  cout<<qen.front().mid[j]<<" ";
                     cout<<endl;
                    for(int j=7;j<=9;j++)
                     cout<<qen.front().mid[j]<<" ";
                     cout<<endl;
                    cout<<endl;
                    for(int j=1;j<=3;j++)
                     cout<<qen.back().mid[j]<<" ";
                     cout<<endl;
                    for(int j=4;j<=6;j++)
                     cout<<qen.back().mid[j]<<" ";
                     cout<<endl;
                    for(int j=7;j<=9;j++)
                     cout<<qen.back().mid[j]<<" ";
                     cout<<endl;
                    cout<<endl;
            cout<<"--------------------------------"<<endl;*/
    //exit(0);
}
/*void cmp(sec &x,sec &y)
{
    for(int i=0;i<=9;i++) x.mid[i]=y.mid[i];
    //exit(2);
    x.pos=y.pos;
    //exit(3);
    x.step=y.step;
    //exit(4);
    return;
}*/
bool judge1()
{//这个来判断是不是在另外的路径上面 
    int t=kd(qfr.back().mid);
    if(m2[t]==0) return false;
    print(m2[t],qfr.back().step);
    return true;
}
bool judge2()
{
    int t=kd(qen.back().mid);
    if(m1[t]==0) return false;
    print(m1[t],qen.back().step);
    return true;
}
bool already(int mp[10],int pd)
{//判断是不是走到上一个路径上面去了 
    if(pd==1)
    {
    /*	int c=kd(mp);
    	cout<<c<<endl;*/
        if(m1[kd(mp)]!=0) return true;
        return false;
    }
    if(pd==2)
    {
    /*	int c=kd(mp);*/
        if(m2[kd(mp)]!=0) return true;
        return false;
    }
    //exit(10);
}
void f1(int mp[10],int step)
{
    int t=kd(mp);
    m1[t]=step;
    return;
}
void f2(int mp[10],int step)
{
    int t=kd(mp);
    m2[t]=step;
    return;
}
/*void bfs()
{
    int i=1;
    i++;
}*/
void add(int i)
{
    sec tmpp;
    tmpp.pos=i;
    tmpp.step=0;
    memcpy(&tmpp.mid,&in,sizeof(in));
    qfr.push(tmpp);
    tmpp.pos=5;
    tmpp.step=0;
    memset(tmpp.mid,0,sizeof(tmpp.mid));
    memcpy(&tmpp.mid,&goal,sizeof(goal));
    qen.push(tmpp);
    return;
}
bool pd(int a,int b,int c)
{
    if(c==1||c==2)
    {
        if(b>9||b<1) return false;
        if((a==6&&b==7)||(a==7&&b==6)||(a==3&&b==4)||(a==4&&b==3)) return false;
        return true;
    }
    else if(b<=9&&b>=1) return true;
    return false;
}
int main()
{
    //freopen("test.in","r",stdin);
   // freopen("out2.out","w",stdout);
   /*cout<<"15";
   exit(0);*/
    int a;
    for(int i=1;i<=9;i++)
     {
     	char c=getchar();
     	in[i]=c-'0';
     	//redi(in[i]);
     	if(in[i]==0)
         a=i;
     }
    add(a);
    //if(qfr.empty()) exit(10);
    //else exit(20);
    int tot=0;
    while((!qfr.empty())&&(!qen.empty()))
    {//run 0
        for(int i=1;i<=4;i++)
        {
            sec tmp1,tmp2;
            //cout<<qfr.front().pos;
            //exit(5);
            //if(qfr.empty()) exit(10010);
            for(int j=0;j<=9;j++) tmp1.mid[j]=qfr.front().mid[j];
            //exit(2);
            tmp1.pos=qfr.front().pos;
            //exit(3);
            tmp1.step=qfr.front().step;
            for(int j=0;j<=9;j++) tmp2.mid[j]=qen.front().mid[j];
            //exit(2);
            tmp2.pos=qen.front().pos;
            //exit(3);
            tmp2.step=qen.front().step;
              qfr.push(tmp1);
            //exit(4);
            //cmp(tmp1,qfr.front());
            //cmp(tmp2,qen.front());
            /*tmp1<=>qfr.front();
            tmp2<=>qen.front();*/
            /*memcpy(&tmp1,&qfr.front(),sizeof(tmp1));
            memcpy(&tmp2,&qen.front(),sizeof(tmp2));*/
            //int nowfir[10],nowlas[10];
            /*memset(nowfir,0,sizeof(nowfir));
            memset(nowlas,0,sizeof(nowlas));
            memcpy(nowfir,tmp1.mid,10*sizeof(nowfir));
            memcpy(nowlas,tmp2.mid,10*sizeof(nowlas));*/
            int tmpos1=tmp1.pos+run[i],tmpos2=tmp2.pos+run[i];//记录0的位置 
            if(pd(tmpos1,tmp1.pos,i))
            {
                swap(tmp1.mid[tmpos1],tmp1.mid[tmp1.pos]);
                tmp1.pos=tmpos1;
                tmp1.step++;
                if(!already(tmp1.mid,1)){
                    qfr.push(tmp1);
                    f1(tmp1.mid,tmp1.step);
                    if(judge1()) return 0;
                }
            }
            if(pd(tmpos2,tmp2.pos,i))
            {
                swap(tmp2.mid[tmpos2],tmp2.mid[tmp2.pos]);
                tmp2.step++;
                tmp2.pos=tmpos2;
                if(!already(tmp2.mid,2)){
                    qen.push(tmp2);
                    tot++;
            /*   for(int j=1;j<=3;j++)
                   cout<<qen.front().mid[j]<<" ";
                    cout<<endl;
                   for(int j=4;j<=6;j++)
                  cout<<qen.front().mid[j]<<" ";
                     cout<<endl;
                    for(int j=7;j<=9;j++)
                     cout<<qen.front().mid[j]<<" ";
                     cout<<endl;
          			  cout<<run[i]<<endl;
                    cout<<endl;
                    for(int j=1;j<=3;j++)
                     cout<<qen.back().mid[j]<<" ";
                     cout<<endl;
                    for(int j=4;j<=6;j++)
                     cout<<qen.back().mid[j]<<" ";
                     cout<<endl;
                    for(int j=6;j<=9;j++)
                     cout<<qen.back().mid[j]<<" ";
                     cout<<endl;
                     cout<<tmp2.step;
                    cout<<endl;
            cout<<"--------------------------------"<<endl;*/
                    f2(tmp2.mid,tmp2.step);
                    if(judge2())return 0;
                }
            }
        }
        qfr.pop();
        qen.pop();
    }
    //bfs();
    return 0;
}
