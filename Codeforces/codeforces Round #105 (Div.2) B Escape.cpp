#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	double v_princess, v_dragon, t, f, c;
	scanf("%lf%lf%lf%lf%lf", &v_princess, &v_dragon, &t, &f, &c);

	if(v_princess >= v_dragon)
	{
		printf("0\n");
		return 0;
	}

	double pos = t * v_princess, t1, t2;
	t2 = pos / (v_dragon - v_princess);
	pos += t2 * v_princess;
	int ans(0);
	while(pos < c)
	{
		ans ++; 
		t1 = pos / v_dragon + f;
		pos += t1 * v_princess;
		t2 = pos / (v_dragon - v_princess);
		pos += t2 * v_princess;
	}
	printf("%d\n", ans);

	return 0;
}
