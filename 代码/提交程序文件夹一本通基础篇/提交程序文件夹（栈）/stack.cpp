#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("stack.in","r",stdin);
    freopen("stack.out","w",stdout);
    int n=0;
    char temp;
    do{
        scanf("%c",&temp);
        if(temp=='(')
            n++;
        if(n>0&&temp==')')
            n--;
        else if(n==0&&temp==')'){
            n=-1;
            break;
        }
    }while(temp!='@');
    if(n==0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
