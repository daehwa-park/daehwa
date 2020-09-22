#include <stdio.h>

int main(void)
{
	int A;
	int B;
	int C;
	int sum, nsum;
	int a[15] = { 0 };
	int b[15] = { 0 };
	int i, j, k, m;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	sum = A * B * C;
	nsum = sum;

	i = 10;
	j = 0;
	while (1)
	{
		a[j] = nsum % i;
		nsum = nsum / i;

		j++;

		if (nsum / 10 == 0)
		{
			a[j] = nsum;
			break;
		}
	}

	for (k = 0; k <= j; k++)
	{
		switch (a[k])
		{
		case 0:
			b[0]++;
			break;
		case 1:
			b[1]++;
			break;
		case 2:
			b[2]++;
			break;
		case 3:
			b[3]++;
			break;
		case 4:
			b[4]++;
			break;
		case 5:
			b[5]++;
			break;
		case 6:
			b[6]++;
			break;
		case 7:
			b[7]++;
			break;
		case 8:
			b[8]++;
			break;
		case 9:
			b[9]++;
			break;
		}
	}

	for (m = 0; m < 10; m++)
	{
		printf("%d\n", b[m]);
	}

	return 0;
}