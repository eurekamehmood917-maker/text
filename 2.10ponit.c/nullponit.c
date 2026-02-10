#include<stdio.h>

int main(void)
{
	int* p=NULL;
	if(p==NULL)
	{
		printf("ERROR MESSAGE\n");
		return -1;
	}
	*p=123;
	printf("%d\n",*p);
	return 0;
}
