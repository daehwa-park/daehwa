#include <stdio.h>

#define SIZE 10

int main(void)
{
	int a[SIZE] = { 0 };
	char ans;
	int i;
	int s1;
	int s2;

	while (1)
	{
		printf("좌석을 예약하시겠습니까? (y 또는 n) ");
		scanf("%c", &ans);
	
		if (ans == 'y')
		{
			printf("------------------------------\n");
			printf(" 1 2 3 4 5 6 7 8 9 10\n");
			printf("------------------------------\n");

			for (i = 0; i < SIZE; i++)
				printf(" %d", a[i]);
			printf("\n");

			printf("몇번째 좌석을 예약하시겠습니까? ");
			scanf("%d %d", &s1, &s2);
			if (s1 <= 0 || s1 > SIZE)
			{
				printf("다시\n");
				continue;
			}
			if (s2 <= 0 || s2 > SIZE)
			{
				printf("다시\n");
				continue;
			}

			if (a[s1 - 1] == 0 && a[s2 - 1] == 0)
			{
				a[s1 - 1] = 1;
				a[s2 - 1] = 1;
				printf("예약되었습니다.\n");
			}
			else if (a[s1 - 1] == 1 && a[s2 - 1] == 0)
			{
				printf("%d번이 이미 예약된 자리\n", s1);
			}
			else if (a[s1 - 1] == 0 && a[s2 - 1] == 1)
				printf("%d번이 이미 예약된 자리\n", s2);
			else 
				printf("둘다 이미 예약된 자리\n");
		}

		if (ans == 'n')
			break;
	}
	return 0;
	
}

