#include<stdio.h>

int main(void)
{	
	int i=0;
	char arr[10];

	for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
	{
		scanf("%c",&arr[i]);
	}
	for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
	{
		printf("arr[%d]=%d\n",i,arr[i]);
	}
	return 0;

}

