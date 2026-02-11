#include<stdio.h>
#include<string.h>

int main(void)
{
	char arr[10]="hello";
	char* scr = "world";

	printf("arr=%s\n",arr);
	
	printf("arr=%s\n",strcpy(arr,scr));
	return 0;
}
