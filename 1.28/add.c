#include<stdio.h>

int add(int a,int b)
{
	return a+b;

}

int main(void)
{
	int (*aadd)(int a,int b)=&add;
	
	aadd(2,5);
	printf("%d\n",add(2,5));
	
	return 0;
}
