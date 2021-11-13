#pragma GCC optimize(2) 
#include<bits/stdc++.h>
using namespace std;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
template <typename T> inline void redi(T& t)
{
	register int c=getchar();t=0;
	if(c=='-') t=-1;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) t=t*10+c-'0',c=getchar();
}
template <typename T,typename... Args>inline void redi(T& t,Args&... args)
{
	redi(t);
	redi(args...);
}
#define maxx 100005
int t,r,c,n,tmphang,tmplie;//t组数据，r行c列，n个已经确定的点 
bool flag[maxx],used[maxx],hangb,lieb;
int as_l,as_h;//行列需要满足的条件(差为恒定的值) 
int in[maxx][3];//输入的东西0,1hang,2lie分别存填入的数字，ri和ci 
void solveboth(int x,int aa,int bb,int cc)
{
	int jl,jh;
	int D1=in[aa][0],D2=in[bb][0],D3=in[cc][0];
	int a32=in[cc][1]-in[bb][1];
	int a21=in[bb][1]-in[aa][1];
	int b32=in[cc][2]-in[bb][2];
	int b21=in[bb][2]-in[aa][1];
	if(b21*a32-a21*b32!=0)
	 jl=100.0*((D2-D1)*a32-(D3-D2)*a21)/(b21*a32-a21*b32);
	if(b21*a32-a21*b32==0) jl=0;
	if(a21*b32-b21*a32!=0)
	 jh=100.0*((D2-D1)*b32-(D3-D2)*b21)/(a21*b32-b21*a32);
	if(a21*b32-b21*a32==0) jh=0;
	if(jl%100!=0||jh%100!=0){
		flag[x]=true;
		return;
	}
	as_l=jl/100;
	as_h=jh/100;
	return;
}
bool judge(int hang,int lie,int data)
{//以第一个为端点 
	if(data==(as_h*(hang-in[1][1])+as_l*(lie-in[1][2]))){
		return false;
	}
	return true;
}
bool judge2(int hang,int lie)
{
	int data=as_h*(hang-in[1][1])+as_l*(lie-in[1][2]);
	if(data<0)return true;
	return false;
}
void f(int now)
{
	if(hangb&&lieb) solveboth(now,1,tmphang,tmplie);
	else if(hangb==true){
		solveboth(now,1,tmphang,tmphang);//这个是只给了一行 
	}
	else if(lieb==true){
		solveboth(now,1,tmplie,tmplie);//这个是只给了一列 
	}//不可能有其他的情况（老师应该不会那么坑） 
	/*if((!hangb)&&lieb) solvelie();
	if((!lieb)&&hangb) solvehang();*/
	if(flag[now]==true) return;
	for(int i=1;i<=n;i++)
	 if(judge(in[i][1],in[i][2],in[i][0])) {
	 	flag[now]=true;
	 	return;
	 }
	hangb=lieb=false;
	 if(judge2(1,1)||judge2(1,c)||judge2(r,1)||judge2(r,c)){
	 	flag[now]=true;
	 	return;
	 }
	 return;
}
void f2(int now)
{//有两个点 
	srand(time(0));
	int hang1=in[1][1],hang2=in[2][1],lie1=in[1][2],lie2=in[2][2];
	int data1=in[1][0],data2=in[2][0]; 
	if(hang1==hang2){//所处的行一样 
		int delta=100.0*(data2-data1)/(lie2-lie1);
		if(delta%100!=0){
			flag[now]=true;
			return;
		}
		if((data1-(lie1-1)*delta>=0)&&(data1+(c-lie1)*delta>=0)){
			return;
		}
		flag[now]=true;
		return;
	}
	if(lie1==lie2){//所处同一列 
		int delta=100.0*(data2-data1)/(hang2-hang1);
		if(delta%100!=0){
			flag[now]=true;
			return;
		}
		if((data1-(hang1-1)*delta>=0)&&(data1+(c-hang1)*delta>=0)){
			return;
		}
		flag[now]=true;
		return;
	}
	flag[now]=true;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	redi(t);
	int ri,ci,ni;
	//used[1]=true;
	for(int i=1;i<=t;i++)
	 {
	 	tmplie=tmphang=0;
	 	redi(r,c,n);//a*b的棋盘，c个已经填好的点 
	 	/*for(int j=2;j<=c;j++)
	 	 used[j]=false;*/
	 	for(int j=1;j<=n;j++)
	 	{
	 		scanf("%d%d%d",in[j][1],in[j][2],in[j][0]);
	 		//redi();
	 		if(in[j][0]<0) flag[i]=true;
	 		if(in[j][1]!=in[1][1]) {//表示有不同的行 
	 			tmphang=j;
	 			hangb=true;
	 		}
	 		if(in[j][2]!=in[1][2]&&tmphang!=j){//表示有不同的列 
	 			tmplie=j;
	 			lieb=true;
	 		}
	 	}
	 	if(flag[i]==true){
	 		printf("No\n");
			continue;
	 	} 
	 	if(n>=3){
	 		f(i);
	 		if(flag[i]==true) {
	 			printf("No\n");
	 			continue;
	 		}
	 		else{
	 			printf("Yes\n");
	 			continue;
	 		}
	 	}
	 	if(n==1){
	 		printf("Yes\n");
	 		continue;
	 	}
	 	if(n==2){
	 		f2(i);
	 		if(flag[i]==true) {
	 			printf("No\n");
	 			continue;
	 		}
	 		else{
	 			printf("Yes\n");
	 			continue;
	 		}
	 		
	 	}
	 }
	 return 0;
}
