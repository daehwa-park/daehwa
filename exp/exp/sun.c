#include <stdio.h>

int main(void)
{
	int A;
	int B;
	int C;

	scanf("%d %d %d", &A, &B, &C);

	if (A > B)
		if (C > B)
			if (A > C)
				printf("%d", C);
			else
				printf("%d", A);
		else
			printf("%d", B);
	else if(B> A)
		if(C> A)
			if(B>C)
				printf("%d", C);
			else
				printf("%d", B);
		else
			printf("%d", A);
	else 
		printf("%d", B);

	return 0;
}