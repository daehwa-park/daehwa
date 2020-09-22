#include <stdio.h>

int main(void)
{
	int min;
	int max;
	int a[13];
	int i;
	int j;
	int k;
	int n;


	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf(" %d", &a[i]);
	}

	min = a[0];

	for (j = 1; j < n; j++)
	{
		if (min > a[j])
			min = a[j];
		else
			continue;
	}

	max = a[0];

	for (k = 1; k < n; k++)
	{
		if (max < a[k])
			max = a[k];
		else
			continue;
	}
	
	printf("%d %d\n", min, max);

	return 0;
}