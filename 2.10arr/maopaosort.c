#include<stdio.h>

void print(int* arr,int size);
void sort(int* arr,int size);

void sort(int* arr,int size)
{
	int i=0,j=0;
	int tmp=0;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				
			}
		}
	}
}
void print(int* arr,int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\n");
}

int main(void)
{
	int arr[10]={15,165,45,13,46,79,56,58,95,32};
	int size=sizeof(arr)/sizeof(*arr);
	
	print(arr,size);

	sort(arr,size);

	print(arr,size);

	return 0;
}
