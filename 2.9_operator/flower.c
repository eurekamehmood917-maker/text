#include<stdio.h>

int main(void)
{
	int b=0,s=0,g=0;
	int n=0;
	
	for(n=100;n<1000;n++)
	{
		b=n/100;
		s=n/10%10;
		g=n%10;

		if(b*b*b+s*s*s+g*g*g==n)
			printf("%d\n",n);
	}
	return 0;
}

