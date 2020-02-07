#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

void fcn(int i,int sort[],int which[],int size, int num);
int search(int which[], int r);


int compare (const void * a, const void * b)
{
	  return ( *(int*)b - *(int*)a );
}


int main ()
{
	int size;
	scanf("%d",&size);
	
	int array[size];
	for(int i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	
	/*orginal level*/
	int which[4];
	for(int i=0;i<4;i++)
	{
		scanf("%d",&which[i]);
	}
	

	for(int i=0; i<size; i++)
	{
		if(array[i]<4)
		{
			array[i]=array[i]+52;
		}
	}

	/* add factor for change level*/
	int change[4];
	for(int i=0;i<4;i++)
	{
		change[i] = 103-i-which[i]; 
	}
	
	/*change before sort*/
	int sort[size];
	for(int i=0;i<size;i++)
	{
		sort[i]=array[i]+change[search(which,array[i]%4)];
	}
	
	/* qsort */
	qsort (sort, size, sizeof(int), compare);

	for (int i=0; i<size; i++)
	{	
		if(sort[i]/4==1)
		{
			fcn(i, sort, which,size,2);
		}
		else if(sort[i]/4==2)
		{
			fcn(i, sort, which,size,3);
		}
		else if(sort[i]/4==3)
		{		
			fcn(i, sort, which,size,4);
		}
		else if(sort[i]/4==4)
		{
			fcn(i, sort, which,size,5);
		}
		else if(sort[i]/4==5)
		{
			fcn(i, sort, which,size,6);
		}
		else if(sort[i]/4==6)
		{
			fcn(i, sort, which,size,7);
		}
		else if(sort[i]/4==7)
		{
			fcn(i, sort, which,size,8);
		}
		else if(sort[i]/4==8)
		{		
			fcn(i, sort, which,size,9);
		}
		else if(sort[i]/4==9)
		{	
			fcn(i, sort, which,size,10);
		}
		else if(sort[i]/4==10)
		{
			fcn( i, sort, which,size,11);
		}
		else if(sort[i]/4==11)
		{	
			fcn( i, sort, which,size,12);
		}
		else if(sort[i]/4==12)
		{	
			fcn( i, sort, which,size,13);
		}
		else if(sort[i]/4==13)
		{
			fcn( i, sort, which,size,1);
		}

	}
	printf("\n");
	return 0;
}


void fcn(int i,int sort[],int which[],int size, int num )
{
		if(num<11&num>1)
		{	
			if(sort[i]%4==3)
			{
				if(which[0]==100){printf("H%d ",num);}
				else if(which[0]==101) {printf("D%d ",num);}
				else if(which[0]==102) {printf("C%d ",num);}
				else if(which[0]==103) {printf("S%d ",num);}
			}
			else if(sort[i]%4==2)
			{	
				if(which[1]==100){printf("H%d ",num);}
				else if(which[1]==101) {printf("D%d ",num);}
				else if(which[1]==102) {printf("C%d ",num);}
				else if(which[1]==103) {printf("S%d ",num);}
			}
			else if(sort[i]%4==1)
			{	
				if(which[2]==100){printf("H%d ",num);}
				else if(which[2]==101) {printf("D%d ",num);}
				else if(which[2]==102) {printf("C%d ",num);}
				else if(which[2]==103) {printf("S%d ",num);}
			}else if(sort[i]%4==0)
			{	
				if(which[3]==100){printf("H%d ",num);}
				else if(which[3]==101){printf("D%d ",num);}
				else if(which[3]==102){printf("C%d ",num);}
				else if(which[3]==103){printf("S%d ",num);}
			}
			
		}
		else if(num==11)
		{
			if(sort[i]%4==3)
			{	
				if(which[0]==100){printf("HJ ");}
				else if(which[0]==101) {printf("DJ ");}
				else if(which[0]==102) {printf("CJ ");}
				else if(which[0]==103) {printf("SJ ");}
			}
			else if(sort[i]%4==2)
			{	
				if(which[1]==100){printf("HJ ");}
				else if(which[1]==101) {printf("DJ ");}
				else if(which[1]==102) {printf("CJ ");}
				else if(which[1]==103) {printf("SJ ");}
			}
			else if(sort[i]%4==1)
			{	
				if(which[2]==100){printf("HJ ");}
				else if(which[2]==101) {printf("DJ ");}
				else if(which[2]==102) {printf("CJ ");}
				else if(which[2]==103) {printf("SJ ");}
			}else if(sort[i]%4==0)
			{	
				if(which[3]==100){printf("HJ ");}
				else if(which[3]==101){printf("DJ ");}
				else if(which[3]==102){printf("CJ ");}
				else if(which[3]==103){printf("SJ ");}
			}
		
		}
		else if(num==12)
		{
			if(sort[i]%4==3)
			{	
				if(which[0]==100){printf("HQ ");}
				else if(which[0]==101) {printf("DQ ");}
				else if(which[0]==102) {printf("CQ ");}
				else if(which[0]==103) {printf("SQ ");}
			}
			else if(sort[i]%4==2)
			{	
				if(which[1]==100){printf("HQ ",num);}
				else if(which[1]==101) {printf("DQ ");}
				else if(which[1]==102) {printf("CQ ");}
				else if(which[1]==103) {printf("SQ ");}
			}
			else if(sort[i]%4==1)
			{	
				if(which[2]==100){printf("HQ ");}
				else if(which[2]==101) {printf("DQ ");}
				else if(which[2]==102) {printf("CQ ");}
				else if(which[2]==103) {printf("SQ ");}
			}else if(sort[i]%4==0)
			{	
				if(which[3]==100){printf("HQ ");}
				else if(which[3]==101){printf("DQ ");}
				else if(which[3]==102){printf("CQ ");}
				else if(which[3]==103){printf("SQ ");}
			}
			
		}
		else if(num==13)
		{
			if(sort[i]%4==3)
			{	
				if(which[0]==100){printf("HK ",num);}
				else if(which[0]==101) {printf("DK ");}
				else if(which[0]==102) {printf("CK ");}
				else if(which[0]==103) {printf("SK ");}
			}
			else if(sort[i]%4==2)
			{	
				if(which[1]==100){printf("HK ");}
				else if(which[1]==101) {printf("DK ");}
				else if(which[1]==102) {printf("CK ");}
				else if(which[1]==103) {printf("SK ");}
			}
			else if(sort[i]%4==1)
			{	
				if(which[2]==100){printf("HK ");}
				else if(which[2]==101) {printf("DK ");}
				else if(which[2]==102) {printf("CK ");}
				else if(which[2]==103) {printf("SK ");}
			}else if(sort[i]%4==0)
			{	
				if(which[3]==100){printf("HK ");}
				else if(which[3]==101){printf("DK ");}
				else if(which[3]==102){printf("CK ");}
				else if(which[3]==103){printf("SK ");}
			}
		
	
		}
		else if(num==1)
		{
			if(sort[i]%4==3)
			{	
				if(which[0]==100){printf("HA ");}
				else if(which[0]==101) {printf("DA ");}
				else if(which[0]==102) {printf("CA ");}
				else if(which[0]==103) {printf("SA ");}
			}
			else if(sort[i]%4==2)
			{	
				if(which[1]==100){printf("HA ");}
				else if(which[1]==101) {printf("DA ");}
				else if(which[1]==102) {printf("CA ");}
				else if(which[1]==103) {printf("SA ");}
			}
			else if(sort[i]%4==1)
			{	
				if(which[2]==100){printf("HA ");}
				else if(which[2]==101) {printf("DA ");}
				else if(which[2]==102) {printf("CA ");}
				else if(which[2]==103) {printf("SA ");}
			}else if(sort[i]%4==0)
			{	
				if(which[3]==100){printf("HA ");}
				else if(which[3]==101){printf("DA ");}
				else if(which[3]==102){printf("CA ");}
				else if(which[3]==103){printf("SA ");}
			}
		}
}

int search(int which[],int r)
{
	for(int i=0; i< 4 ;i++)
	{
		if(which[i]==r+100)
		{
			return i;
		}	
	}
}

