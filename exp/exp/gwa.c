#include <stdio.h>

void get_sum_diff(int x, int y, int *p_sum, int *p_diff);

int main()
{
	int a, b;
	int p_s, p_d;

	scanf("%d %d", &a, &b);         //두 정수를 받음

	get_sum_diff(a, b, &p_s, &p_d);

	printf("두 정수의 합 : %d\n", p_s);  //합과 차를 출력
	printf("두 정수의 차 : %d\n", p_d);

	return 0;
}

void get_sum_diff(int x, int y, int *p_sum, int *p_diff)
{
	*p_sum = x + y;                //포인터에 합과 차를 저장
	*p_diff = x - y;

}