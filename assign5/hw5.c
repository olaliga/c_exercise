#include <stdio.h>

void sort(int a[],int size);


int main() {
		int num;
		scanf("%d",&num);
	while(num>0)
	{
		int a[num];
		int how;
		for(int i=0;i<num;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&how);	
		sort(a,num);	
		for(int i=0;i<num;)
		
		

		/*for test*/
		printf("%d \n",num);
		printf("%d \n",how);
		for(int j=0;j<num;j++)
		{
			printf("%d",a[j]);
		}
		printf("\n");
		/**/

		scanf("%d",&num);
	}
	return 0;
}

void sort (int a[],int size)
{
	int pass;
	int i;
	int hold; 
	for(pass=1;pass < size;pass++){
		for(i=0;i<size-1;i++){
			if(a[i]<a[i+1])
			{
				hold = a[i+1];
				a[i+1]=a[i];
		 		a[i]=hold;		
			}
		}
	}	
}


void combin(int data[], int save[], int how, int size )
{
	if()
	{
	}
	else
	





}	

