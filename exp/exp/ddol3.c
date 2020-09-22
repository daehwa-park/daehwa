#include<stdio.h>
#include<stdlib.h>


int main()
{
	int T, W, H, N, F, R;
	int i, j;
	int *a = NULL;


	scanf("%d", &T);

	a = (int *)malloc(T * sizeof(int));

	for (i = 0; i < T; i++)
	{
		scanf("%d %d %d", &H, &W, &N);

		F = N % H;
		R = N / H;
		

		if (F == 0)
		{
			a[i] = H * 100 + ((R / 10) * 10) + R % 10;
		}
		else
			a[i] = F * 100 + ((R / 10) * 10) + R % 10 + 1;
	}
	for (j = 0; j < T; j++)
	{
		printf("%d\n", a[j]);
	}
	free(a);
}