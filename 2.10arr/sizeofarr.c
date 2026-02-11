#include<stdio.h>

int main(void)
{
	int i=0;
	int arr[5];
	
	for(i=0;i<5;i++)
	{
		printf("sizeof(arr[%d])=%ld\n",i,sizeof(arr[i]));
	}
	return 0;
}
