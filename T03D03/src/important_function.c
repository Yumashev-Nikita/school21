#include <stdio.h>
#include <math.h>

int main()
{
	float x;
	if (scanf("%f", &x) == 1)
	{
		printf("%.1f", 0.007 * pow(x, 4.0) +
			   	((22.8 * pow(x, 1.0 / 3.0) - 1000) * x + 3) /
			   	(x * x / 2.0) - x * (pow(10.0 + x, 2.0 / x)) - 1.01);
	}
	else
	{
		printf("n/a");
	}
    return 0;
}
