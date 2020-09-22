#include <stdio.h>

int main(void)
{
	int N;
	int S;
	int a;
	int b;
	int sum;
	int len;

	scanf("%d", &N);

	S = N;

	len = 0;
	do
	{
		if (S < 10)
		{
			a = 0;
			b = S;
		}
		else
		{
			a = S / 10;
			b = S % 10;
		}

		sum = a + b;

		if (sum < 10)
		{
			S = sum + (b * 10);
		}
		else
		{
			S = (sum % 10) + (b * 10);
		}


		
		len++;
	} while (N != S);

	printf("%d", len);
	return 0;
}