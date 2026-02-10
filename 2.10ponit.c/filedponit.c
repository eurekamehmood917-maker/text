#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int* p=NULL;

	p=malloc(sizeof(*p));
	if(p==NULL)
	{
		printf("创建失败\n");
		return -1;
	}

	*p=123;
	printf("%p\n",p);
	printf("%d\n",*p);
	return 0;
}
