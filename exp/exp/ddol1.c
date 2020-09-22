#include<stdio.h>

int main()
{
	int X;
	int len = 64;
	int temp= 0;
	int i = 1;
	
	scanf("%d", &X);

	while (1) {

		if (temp + len > X)
		{
			if (temp + (len / 2) < X)
			{
				i++;
				temp = temp + (len / 2);

				if (temp == X)
					break;

			}


			len = len / 2;

		}
		else
			break;
		
	}
	printf("%d\n", i);
}