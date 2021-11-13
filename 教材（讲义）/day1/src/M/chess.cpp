#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e4+5;
const int MaxM=1e2+5;
const int oo=1047483647;
typedef pair<int,int> pii;
template<class T> void read(T &re);

vector<pii> head[MaxN*2];
void add_edge(int from,int towards,int val){head[from].push_back(make_pair(towards,val));}

int m,n,mapp[MaxM][MaxM],numb[MaxM][MaxM],dis[MaxN*2];
bool mark[MaxN*2];

inline void DJ(int start)//最短路1~m*m
{
	priority_queue <pii,vector<pii>,greater<pii> > que;
	for(int i=1;i<=m*m*2;i++) dis[i]=oo;

	dis[start]=0;
	que.push(make_pair(dis[start],start));

	while(!que.empty())
	{
		pii tt=que.top();
		que.pop();
		int loc=tt.second;

		if(mark[loc]) continue;
		mark[loc]=1;

		pii tmp;
		for(unsigned int i=0;i<head[loc].size();++i)
		{
			tmp=head[loc][i];
			if(dis[tmp.first] > dis[loc]+(tmp.second))
			{
				dis[tmp.first]=dis[loc]+tmp.second;
				que.push(make_pair(dis[tmp.first],tmp.first));
			}
		}
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(m);read(n);
	int tx,ty,td;
	for(int i=1;i<=n;i++){//存图 0-白 1-红 2-黄
		read(tx);read(ty);read(td);td++;
		mapp[tx][ty]=td;
	}

	int tnum=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){//标记每个点的序号
			numb[i][j]=++tnum;
		}
	}

	for(int i=1;i<=m;i++){//加边
		for(int j=1;j<=m;j++){
			if(mapp[i][j]==0){//白点，则将其视作两个点，分别是涂成红色和涂成黄色两种情况
				if(i>1&&mapp[i-1][j]){
					if(mapp[i-1][j]==1){
						add_edge(numb[i][j],numb[i-1][j],0);
						add_edge(numb[i][j]+m*m,numb[i-1][j],1);
					}else{
						add_edge(numb[i][j],numb[i-1][j],1);
						add_edge(numb[i][j]+m*m,numb[i-1][j],0);
					}
				}
				if(i<m&&mapp[i+1][j]){
					if(mapp[i+1][j]==1){
						add_edge(numb[i][j],numb[i+1][j],0);
						add_edge(numb[i][j]+m*m,numb[i+1][j],1);
					}else{
						add_edge(numb[i][j],numb[i+1][j],1);
						add_edge(numb[i][j]+m*m,numb[i+1][j],0);
					}
				}
				if(j>1&&mapp[i][j-1]){
					if(mapp[i][j-1]==1){
						add_edge(numb[i][j],numb[i][j-1],0);
						add_edge(numb[i][j]+m*m,numb[i][j-1],1);
					}else{
						add_edge(numb[i][j],numb[i][j-1],1);
						add_edge(numb[i][j]+m*m,numb[i][j-1],0);
					}
				}
				if(j<m&&mapp[i][j+1]){
					if(mapp[i][j+1]==1){
						add_edge(numb[i][j],numb[i][j+1],0);
						add_edge(numb[i][j]+m*m,numb[i][j+1],1);
					}else{
						add_edge(numb[i][j],numb[i][j+1],1);
						add_edge(numb[i][j]+m*m,numb[i][j+1],0);
					}
				}
			}else{//是有颜色的点，则通向同色费用为0，异色为1，同色白色为2，异色白色为3
				if(i>1){
					if(mapp[i-1][j]==0){
						if(mapp[i][j]==1){
							add_edge(numb[i][j],numb[i-1][j],2);
							add_edge(numb[i][j],numb[i-1][j]+m*m,3);
						}else{
							add_edge(numb[i][j],numb[i-1][j],3);
							add_edge(numb[i][j],numb[i-1][j]+m*m,2);
						}
					}else if(mapp[i-1][j]==mapp[i][j]){
						add_edge(numb[i][j],numb[i-1][j],0);
					}else{
						add_edge(numb[i][j],numb[i-1][j],1);
					}
				}
				if(i<m){
					if(mapp[i+1][j]==0){
						if(mapp[i][j]==1){
							add_edge(numb[i][j],numb[i+1][j],2);
							add_edge(numb[i][j],numb[i+1][j]+m*m,3);
						}else{
							add_edge(numb[i][j],numb[i+1][j],3);
							add_edge(numb[i][j],numb[i+1][j]+m*m,2);
						}
					}else if(mapp[i+1][j]==mapp[i][j]){
						add_edge(numb[i][j],numb[i+1][j],0);
					}else{
						add_edge(numb[i][j],numb[i+1][j],1);
					}
				}
				if(j>1){
					if(mapp[i][j-1]==0){
						if(mapp[i][j]==1){
							add_edge(numb[i][j],numb[i][j-1],2);
							add_edge(numb[i][j],numb[i][j-1]+m*m,3);
						}else{
							add_edge(numb[i][j],numb[i][j-1],3);
							add_edge(numb[i][j],numb[i][j-1]+m*m,2);
						}
					}else if(mapp[i][j-1]==mapp[i][j]){
						add_edge(numb[i][j],numb[i][j-1],0);
					}else{
						add_edge(numb[i][j],numb[i][j-1],1);
					}
				}
				if(j<m){
					if(mapp[i][j+1]==0){
						if(mapp[i][j]==1){
							add_edge(numb[i][j],numb[i][j+1],2);
							add_edge(numb[i][j],numb[i][j+1]+m*m,3);
						}else{
							add_edge(numb[i][j],numb[i][j+1],3);
							add_edge(numb[i][j],numb[i][j+1]+m*m,2);
						}
					}else if(mapp[i][j+1]==mapp[i][j]){
						add_edge(numb[i][j],numb[i][j+1],0);
					}else{
						add_edge(numb[i][j],numb[i][j+1],1);
					}
				}
			}
		}
	}
	DJ(1);
	if(mapp[m][m]==0){
		printf("%d\n",(dis[m*m]>=oo&&dis[m*m*2]>=oo) ? -1 : min(dis[m*m],dis[m*m*2]));
	}else{
		printf("%d\n",dis[m*m]>=oo ? -1 : dis[m*m]);
	}
	return 0;
}

template<class T> void read(T &re)
{
	re=0;
	T sign=1;
	char tmp;
	while((tmp=getchar())&&(tmp<'0'||tmp>'9')) if(tmp=='-') sign=-1;
	re=tmp-'0';
	while((tmp=getchar())&&(tmp>='0'&&tmp<='9')) re=re*10+(tmp-'0');
	re*=sign;
}