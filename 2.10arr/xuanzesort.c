#include<stdio.h>

void print(int* arr,int size);
void sort(int* arr,int size);

void sort(int* p,int size)
{
	int i=0,j=0;
	int k=0;
	int tmp=0;
	for(i=0;i<size;i++)
	{
		k=i;
		for(j=i+1;j<size;j++)
			{
				if(p[k]>p[j])
				{
					k=j;
				}
			}
			if(i!=k)
			{
				tmp=p[i];
				p[i]=p[k];
				p[k]=tmp;
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
