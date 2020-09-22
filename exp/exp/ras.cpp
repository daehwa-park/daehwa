#include <stdio.h>

int main()
{
     char c[5];
     int i = 0;
     printf("insert\n");
     for (i = 0; i<5; i++)
	     {
		         scanf("%c", &c[i]);
	     }
	
	   for (i = 4; i>=0; i--)
	  {
	      printf("%c", c[i]);
	    }
	    return 0;
}
