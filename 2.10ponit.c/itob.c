#include<stdio.h>

void itob(int num);
void itoo(int num);
void itox(int num);

void itox(int num)
{
	int tme=num;
	while(tme)
	{
		printf("%d",tme%16);
		tme /=16;
	}
	printf("\n");

}
void itoo(int num)
{
	int tme=num;
	while(tme)
	{
		printf("%d",tme%8);
		tme /=8;
	}
	printf("\n");
}
void itob(int num)
{
	int t=num;
	while(t)
	{
		printf("%d",t%2);
		t /=2;
	}
	printf("\n");
}

int main(void)
{
	int num=0;
	scanf("%d",&num);

	itob(num);
	itoo(num);
	itox(num);
	printf("%d\n",num);
	return 0;

}
