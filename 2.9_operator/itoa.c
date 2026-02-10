#include<stdio.h>

int main(void)
{
	char buff[5]={0};
	buff[0]=1234/1000+'0';
	buff[1]=1234/100%10+'0';
	buff[2]=1234/10%10+'0';
	buff[3]=1234%10+'0';
	

	printf("%s\n",buff);
	return 0;

}
