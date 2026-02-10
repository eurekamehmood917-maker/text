#include<stdio.h>

int max(int a,int b);

int max(int a,int b)
{
	
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main(void)
{
	int a=0,b=0;
	int num=0;
	scanf("%d-%d",&a,&b);

	num=max(a,b);
	printf("%d\n",num);

	return 0;

	

}
