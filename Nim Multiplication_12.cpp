#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int pre[2][2] = {0, 0, 0, 1};

int nimMultiPower(int x, int y)
{
	if(x <= 1) return pre[x][y];

	int i;
	for(i = 0; ; i++)
	{
		if(x >= (1 << (1 << i)) && x < (1 << (1 << (i + 1))))
			break;
	}

	int M = (1 << (1 << i));
	
	int P = x / M;
	int S = y / M, T = y % M;
	
	int d1 = nimMultiPower(P, S);
	int d2 = nimMultiPower(P, T);
	
	return (M * (d1 ^ d2)) ^ nimMultiPower(M / 2, d1);
}


int nimMulti(int x, int y)
{
	if(x < y) return nimMulti(y, x);
	if(x <= 1) return pre[x][y];

	int i;
	for(i = 0; ; i++)
    {
		if(x >= (1 << (1 << i)) && x < (1 << (1 << (i + 1))))
			break;
    }

	int M = (1 << (1 << i));

	int p = x / M, q = x % M;
    int s = y / M, t = y % M;   

    int c1 = nimMulti(p, s);
	int c2 = nimMulti(p, t) ^ nimMulti(q, s);
	int c3 = nimMulti(q, t);

	return ((c1 ^ c2) * M) ^ c3 ^ nimMultiPower(M / 2, c1);
}


int main()
{
	int T;
    int a, b;

	scanf("%d", &T);
	while(T--)
    {
		int n;
		scanf("%d", &n);

		int res = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			res ^= nimMulti(a, b);
		}

		if(res == 0) printf("Don't waste your time.\n");
		else printf("Have a try, lxhgww.\n");
	}
}