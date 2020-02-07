#include <stdio.h>
#include <math.h>

int main() {
	int size;
	scanf("%d",&size);
	int sudoku[size][size];
	int i;
	int j;
	int k;
	int l;
	int sum;
	int ans;
	int stop;


	ans=0;
	stop=(1+size)*size/2;

/*scan sudoku*/
	for(i=0;i < size;i++)
	{
		for(j=0;j < size;j++)
		{
			scanf("%d",&sudoku[i][j]);
		}
	}

	for(i=0;i < size;i++)
	{
		sum=0;
		for(j=0;j < size;j++)
		{
			sum=sum+sudoku[i][j];
		}
	
		if(sum!=stop)
		{		
			ans++;
			break;
		}
	}

	for(j=0;j < size;j++)
		{
			sum=0;
			for(i=0;i < size;i++)
			{
				sum=sum+sudoku[i][j];
			}
			if(sum!=stop)
			{
				ans++;
				break;
			}
		}

		for(l=0;l<sqrt(size);l++)
		{
			for(k=0;k<sqrt(size);k++)
			{	
				sum=0;
				for(i=0+k*(sqrt(size));i<(k+1)*(sqrt(size));i++)
				{
					for(j=0+l*(sqrt(size));j<(l+1)*(sqrt(size));j++)
					{
						sum=sum+sudoku[i][j];
					}
				}
				if(sum!=stop)
				{
					ans++;
					break;
				}	
			}
		}

		if(ans==0)
		{
			printf("Correct\n");
		}
		else
		{
			printf("Wrong\n");
		}
		return 0;
}
