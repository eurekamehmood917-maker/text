#include<stdio.h>
#include<string.h>

int main(void)
{
	char arr[10]="hello";
	char* scr = "world";

//	printf("arr=%s\n",arr);
	
///	printf("arr=%s\n",strcpy(arr,scr));
	printf("%d\n",strcmp(arr,scr));
	return 0;
}
