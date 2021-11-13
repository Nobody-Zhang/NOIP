
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void PrintfVectorInt(vector<int> &vet)
{
	for (vector<int>::iterator pos = vet.begin(); pos != vet.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');
}
int main()
{
	const int MAXN = 20;
	int a[MAXN];
	int i;
	for (i = 0; i < MAXN; ++i)
		a[i] = rand() % (MAXN * 2);
 
	//动态申请vector 并对vector建堆
	vector<int> *pvet = new vector<int>(40);
	pvet->assign(a, a + MAXN);
 
	//建堆
	make_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);
 
	//加入新数据 先在容器中加入，再调用push_heap()
	pvet->push_back(25);
	push_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);
 
	//删除数据  要先调用pop_heap()，再在容器中删除
	pop_heap(pvet->begin(), pvet->end());
	pvet->pop_back();
	pop_heap(pvet->begin(), pvet->end());
	pvet->pop_back();
	PrintfVectorInt(*pvet);
 
	//堆排序
	sort_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);
 
	delete pvet;
	return 0;
}

