#include <stdio.h>

void get_sum_diff(int x, int y, int *p_sum, int *p_diff);

int main()
{
	int a, b;
	int p_s, p_d;

	scanf("%d %d", &a, &b);         //�� ������ ����

	get_sum_diff(a, b, &p_s, &p_d);

	printf("�� ������ �� : %d\n", p_s);  //�հ� ���� ���
	printf("�� ������ �� : %d\n", p_d);

	return 0;
}

void get_sum_diff(int x, int y, int *p_sum, int *p_diff)
{
	*p_sum = x + y;                //�����Ϳ� �հ� ���� ����
	*p_diff = x - y;

}