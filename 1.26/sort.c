void sort(int* arr,int size)
int i=0,j=0,temp=0;
{
	for(i=0;i<size-1;i++)
	{
		for(int j0;j<size-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
