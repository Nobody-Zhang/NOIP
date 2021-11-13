#include<bits/stdc++.h>
using namespace std;
#define MAXn 100010//定义常量为100010
//注意，不能加"="或者";"
//不然会有错误 
int n,a[MAXn],b[MAXn],sum;//定义数组和总元素个数 
void px(int l,int m,int r)
{
	int i=l,j=m+1,k=l;
	//指针i指向最左边元素
	//指针j指向第二个分数组最左边的元素
	//指针k指向a的第一个元素 
  	memcpy(b+l,a+l,sizeof(int)*(r-l+1));
  	//将a数组拷贝到b组里面 
	while(i<=m&&j<=r){//当两个数组均有元素时
	//可以进行比较 
		if(b[i]<=b[j]) a[k++]=b[i++];
		//将较小的元素存入a数组里面 
		if(b[i]>b[j]) {
			a[k++]=b[j++];//保证a数组里均有序 
			sum+=m-i+1;
			//如果要将后面的元素导入
			//一定会有逆序对产生 
			//当前的数组逆序对个数是当前的i指针到m指针的数的个数 
		}
		
	}
	while(i<=m) a[k++]=b[i++];
	//当后一个里面没有元素时
	//说明前一个的每个元素都比后一个大
	//按照顺序存入a组里面 
	while(j<=r) a[k++]=b[j++];
	//反之亦然 
}
void f1(int l,int r){
	
	if(l<r){
		int m=(l+r)/2;//每个都取其中中间值 
		f1(l,m);//前面二分下去 
		f1(m+1,r);//后面也二分
		//直到所有元素被分成单个元素 
		px(l,m,r);//排序 
	}
}
int main()
{
	cout<<"这个是排序和求逆序对的程序"<<endl;
	cout<<"请输入将要排序数列的个数:";
	cout<<"(Warning:个数只能在100009之内)"<<endl;
	cin>>n;
	cout<<"请输入将要排序数列:"<<endl;
	for(int i=1;i<=n;i++)
	 cin>>a[i];//输入数据 
	f1(1,n);//排序程序开始 
	//这个排序程序结束后，a就是有序数列 
	cout<<"这个数列用归并排序之后的有序数列是:"<<endl; 
	for(int i=1;i<=n;i++)
	 cout<<a[i]<<" ";//输出a数组元素 
	cout<<"\n";//换行 
	cout<<"这个数组里面逆序对有"<<sum<<"个"<<endl;
	//输出逆序对 
	return 0;//结束 
}
