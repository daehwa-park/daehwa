#include<stdio.h>
#include<stdlib.h>

int main() {
	int T, temp;
	int i, j,k,l;
	char gwal[50];
	int *yn = NULL;

	scanf("%d", &T);

	yn = (int*)malloc(sizeof(int) * T);

	for (i = 0; i < T; i++)
	{
		temp = 0;
		
		for (l = 0; l < 50; l++)
		{
			gwal[l] = 0;
		}
		
		scanf("%s", gwal);
	
			
		for (k = 0; gwal[k] != 0; k++)
		{
			if (gwal[k] == '(')
			{
				temp++;
			}
			else if (gwal[k] == ')')
			{
				temp--;
				if (temp < 0)
				{
					yn[i] = 0;
					break;
				}
			
			}
			else {
				printf("°ýÈ£°¡ ¾Æ´Õ´Ï´Ù\n");
				break;
			}
		}

		if (temp == 0)
			yn[i] = 1;
		
	}

	for (j = 0; j < T; j++)
	{
		if (yn[j] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	free(yn);
	return 0;
}