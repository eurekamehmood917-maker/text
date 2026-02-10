#include<stdio.h>

int main(void)
{
	int num=0;
	char *p="1234";

	for(;*p!='\0';p++)
	{	
		num*=10;
		num  += *p-'0';

	}

	printf("%d\n",num);
	
	return 0;
}
