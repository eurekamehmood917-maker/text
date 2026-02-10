#include<stdio.h>

int main(void)
{
/*	int temp=0;
	int a,b;
	scanf("%d %d",&a,&b);

	temp=a;
	a=b;
	b=temp;
	

	printf("a=%d,b=%d",a,b);
	return 0;
*/
	int a,b;
	
	scanf("%d-%d",&a,&b);

	a=a+b;
	b=a-b;
	a=a-b;

	printf("%d-%d",a,b);

	return 0;
}
