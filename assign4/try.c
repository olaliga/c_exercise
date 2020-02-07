#include <stdio.h>
#include <math.h>

int main() {
	int size;
	int sum;
	int i;
	int j;

	size=9;
	sum=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++){
			printf("i %d j %d\n",i,j);
		}
	}
}

