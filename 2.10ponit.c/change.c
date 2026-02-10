#include<stdio.h>

void print(int i)
{
	printf("%d\n",i);
}

void *change(int* i)
{
	scanf("%d",i);
}

int main(void)
{
	int i=99;

	print(i);

	change(&i);

	print(i);
	return 0;
}
