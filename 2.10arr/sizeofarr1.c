#include<stdio.h>
int main(void)
{
	int arr[5];
	int size=sizeof(arr)/sizeof(arr[0]);
	int i=0;

	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<size;i++)
	{
		printf("*(arr+%d)=%d\n",i,*(arr+i));
	}
	return 0;
}

