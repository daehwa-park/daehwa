#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[3][10] = { 0 };
	int i, j, k, m;
	int t;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (i == 0)
				a[i][j] = j + 1;
			if (i == 1)
				a[i][j] = (j + 1)*(j + 1);
			if (i == 2)
				a[i][j] = (j + 1)*(j + 1)*(j + 1);
		}
	}

	scanf("%d", &t);

	for (k = 0; k < 10; k++)
	{
		if (a[2][k] == t)
			printf("%d\n", a[0][k]);
		
	}

	
	return 0;
}