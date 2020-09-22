#include <stdio.h>

int main(void)
{
	int sang;
	int joong;
	int ha;
	int cola;
	int cider;

	int x;
	int y;

	scanf("%d", &sang);
	scanf("%d", &joong);
	scanf("%d", &ha);
	scanf("%d", &cola);
	scanf("%d", &cider);

	if (sang > joong)
		if (joong > ha)
			x = ha;
		else
			x = joong;

	else if (sang < joong)
		if (sang > ha)
			x = ha;
		else
			x = sang;

	else
		if (joong > ha)
			x = ha;
		else
			x = joong;

	if (cola > cider)
		y = cider;
	else
		y = cola;

	printf("%d", x + y - 50);
	
	return 0;
}