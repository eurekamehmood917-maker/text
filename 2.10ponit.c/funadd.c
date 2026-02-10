#include<stdio.h>

int add(int a,int b);//函数的声明
int add(int a,int b)
{
	return a+b;
}


int main(void)
{
	int a=0,b=0;
	int sum=0;

	scanf("%d-%d",&a,&b);

   sum=add(a,b);

   printf("%d\n",sum);
   
   return 0;
}
