#include<stdio.h>

void swap(int* a,int* b);
void swap(int* a,int* b)
{
	int tmp=0;
	tmp=*a;
	*a=*b;
	*b=tmp;
	

}


int main(void)
{
	int a=0,b=0;
	scanf("%d-%d",&a,&b);
	
	printf("a=%d b=%d\n",a,b);
	swap(&a,&b);

	printf("a=%d b=%d\n",a,b);
	return 0;
}

