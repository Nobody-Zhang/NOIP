#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

void test_alg() {
	/*
	int arr[8] = { 1, 1, 1, 5, 3, 4, 2, 3 };
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
	nth_element(arr, arr+5, arr+8);
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
	sort(arr, arr+8);
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
	int *p = lower_bound(arr, arr+8, 3);
	printf("%d\n", *p);
	int ed = unique(arr, arr+8) - arr;
	for(int i = 0; i < ed; i++)
		printf("%d ", arr[i]);
	printf("\n");
	*/
	int a[] = {1, 2, 3, 4};
	//reverse(a, a+4);
	rotate(a, a+2, a+4);
	for(int i = 0; i < 4; i++)
		printf("%d ", a[i]);
	printf("\n");	
	/*
	do {
		for(int i = 0; i < 4; i++)
			printf("%d ", a[i]);
		printf("\n");
	}while(next_permutation(a,a+4));
	*/
}

void test_vector() {
	vector<int> vc;
	for(int i = 1; i <= 10; i++) 
		vc.push_back(i);
	for(int i = 0; i < (int)vc.size(); i++)
		printf("%d\n", vc[i]);
	vc.pop_back();
	for(int i = 0; i < (int)vc.size(); i++)
		printf("%d\n", vc[i]);
	printf("size = %d\n", (int)vc.size());
	printf("front = %d back = %d\n", vc.front(), vc.back());
	vector<int> vvc;
	for(int i = 9; i >= 1; i--)
		vvc.push_back(i);
	printf("%s\n", vc > vvc ? "Greater" : "Less");	
}

void test_set() {
	set<int> st;
	for(int i = 1; i <= 10; i++)
		st.insert(3 * i + 5);
/*	for(set<int>::iterator it = st.begin(); it != st.end(); ++it)
		printf("%d\n", *it);
	st.insert(123);
	st.insert(123);
	for(set<int>::iterator it = st.begin(); it != st.end(); ++it)
		printf("%d\n", *it);
	st.erase(123);*/
	for(set<int>::iterator it = st.begin(); it != st.end(); ++it)
		printf("%d\n", *it);
	printf("%d\n", *st.lower_bound(20));
	printf("%d\n", *st.upper_bound(20));
	printf("%d\n", st.count(20));
	printf("%d\n", st.count(21));
}

void test_map() {
	map<string,int> mp;
	mp["hello"] = 2;
	mp["world"] = 33;
	printf("%d\n", mp["hello"]);
	
	for(map<string,int>::iterator it = mp.begin(); it != mp.end(); ++it)
		printf("%s %d\n", it->first.c_str(), it->second);
}

int main() {
	test_alg();
	
}
