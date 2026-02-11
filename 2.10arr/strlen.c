#include<stdio.h>
#include<string.h>

int main(void)
{
	char dest[10]="hello";
	char* src="world";

	printf("%ld\n",strlen(dest));
	printf("%ld\n",strlen(src));
	
	return 0;
	
}
