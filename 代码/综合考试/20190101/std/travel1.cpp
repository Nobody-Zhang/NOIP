/* Copyright dyj (c) 2015
 *  any codes cannot be used in business
 *  Problem:
 *  社会主义核心价值观
 *  富强 民主 文明 和谐
 *  自由 平等 公正 法治
 *  爱国 敬业 诚信 友善
 *  Socialism Core Value View
 *  Rich Democracy Civilized Harmony
 *  Liberty Equal Justice Law
 *  Nation-loving Job-loving Honesty Friendly
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstring>
#define NAME "travel"

using namespace std;

int N, ord[30], rev[30];

void readin()
{
	string temp;
	cin >> temp;
	N = temp.size();
	for(int i = 0; i < N; ++i)
	{
		ord[i] = temp[i]-'a'+1;
	}
	cin >> temp;
	reverse(temp.begin(), temp.end());
	for(int i = 0; i < N; ++i)
	{
		rev[i] = temp[i]-'a'+1;
	}
}

int dfs(int lo, int ro, int lr, int rr)
{
	int ret = 1;
	for(int i = 1; i < ro-lo; ++i)
	{
		if(ord[lo+i] == rev[lr+i])
		{
			ret *= 2;
		}
		else
		{
			int *temp = find(rev+lr, rev+rr, ord[lo+i]), a, b;
			a = dfs(lo+i, lo+i+rev+rr-temp, temp-rev, rr);
			b = dfs(lo+i+rev+rr-temp, ro, lr+i, temp-rev);
			ret *= a*b;
			break;
		}
	}
	return ret;
}

void process()
{
	cout << dfs(0, N, 0, N) << endl;
}

int main()
{
	freopen(NAME".in", "r", stdin);
#ifndef DEBUG
	freopen(NAME".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);

	readin();
	process();

	return 0;
}
