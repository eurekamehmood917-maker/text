#include<stdio.h>

int main(void)
{
	int i=100;
	int* p=&i;
	int**pp=&p;
	printf("i=%d\n",i);
	printf("*p=%d\n",*p);
	printf("**pp=%d\n",**pp);
	printf("------------------\n");

	printf("&i=%p\n",&i);
	printf("p=%p\n",p);
	printf("*pp=%p\n",*pp);
	
	printf("----------------\n");
	printf("&p=%p\n",&p);
	printf("pp=%p\n",pp);
	return 0;
}
