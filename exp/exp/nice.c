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
		printf("�¼��� �����Ͻðڽ��ϱ�? (y �Ǵ� n) ");
		scanf("%c", &ans);
	
		if (ans == 'y')
		{
			printf("------------------------------\n");
			printf(" 1 2 3 4 5 6 7 8 9 10\n");
			printf("------------------------------\n");

			for (i = 0; i < SIZE; i++)
				printf(" %d", a[i]);
			printf("\n");

			printf("���° �¼��� �����Ͻðڽ��ϱ�? ");
			scanf("%d %d", &s1, &s2);
			if (s1 <= 0 || s1 > SIZE)
			{
				printf("�ٽ�\n");
				continue;
			}
			if (s2 <= 0 || s2 > SIZE)
			{
				printf("�ٽ�\n");
				continue;
			}

			if (a[s1 - 1] == 0 && a[s2 - 1] == 0)
			{
				a[s1 - 1] = 1;
				a[s2 - 1] = 1;
				printf("����Ǿ����ϴ�.\n");
			}
			else if (a[s1 - 1] == 1 && a[s2 - 1] == 0)
			{
				printf("%d���� �̹� ����� �ڸ�\n", s1);
			}
			else if (a[s1 - 1] == 0 && a[s2 - 1] == 1)
				printf("%d���� �̹� ����� �ڸ�\n", s2);
			else 
				printf("�Ѵ� �̹� ����� �ڸ�\n");
		}

		if (ans == 'n')
			break;
	}
	return 0;
	
}

