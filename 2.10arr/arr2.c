#include<stdio.h>

int main(void)
{
	int arr[5];
	int size=sizeof(arr)/sizeof(arr[0]);
	int i=0;

	for(i=0;i<size;i++)
	{
		arr[i]=100+i;
		printf("&arr[%d]=%p\n",i,&arr[i]);
	}
	return 0;

}
