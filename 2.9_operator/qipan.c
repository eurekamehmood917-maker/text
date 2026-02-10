#include<stdio.h>

int main(void)
{
	printf(" 1 2 3 4 5 6 7 8 9 A B C D E F\n");
	int i=0,j=0;
	
	for(i=0;i<15;i++)
	{
		printf("%X", i+1);
		for(j=0;j<15;j++)
	      {	
			 printf("+ ");
		  }
		 printf("\n");
	}

		return 0;
}
