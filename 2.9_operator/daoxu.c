#include<stdio.h>
int main(void)

{
	int n=0;
 	
	scanf("%d",&n);
	while(n)
	
	{
		printf("%d",n%10);
		n /=10;
	}
	printf("\n");
	return 0;


	
}

	
