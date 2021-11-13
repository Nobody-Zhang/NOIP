#include<bits/stdc++.h>
using namespace std;
template <typename T>inline void redi(T& t)
{
    register int c=getchar();
	t=0;
    while(!isdigit(c))
	 c=getchar();
    while(isdigit(c))
	 t=t*10+c-48,c=getchar();
}
template <typename T,typename... Args> inline void redi(T& t, Args&... args)
{
    redi(t);
	redi(args...);
}
int main () {
	//char g;
    int a,b,c,d;
    redi(a,b,c,d);
    cout<<a+b+c+d<<endl;
    return 0;
}
