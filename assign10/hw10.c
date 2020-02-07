#include<stdio.h>
#include<string.h>

void flush(int numfreq[],int flush[]);


int main(){

	struct cards
	{
		char face; // define face
		char *suit;// define suit
		int num;
	};
	typedef struct cards cards;
	char input[80];
	int j=0;

	fgets(input,80,stdin);
	printf("input is %s \n",input);
	cards card_your[13];
	int facefreq[4]={0,0,0,0};

	for(int i=0; i<strlen(input); i++)
	{
		if(input[i]=='S')
		{
			card_your[j].face=input[i];
			j+=1;
			facefreq[0]+=1;
		}
		if(input[i]=='H')
		{
			card_your[j].face=input[i];
			j+=1;
			facefreq[1]+=1;
		}	
		if(input[i]=='D')
		{
			card_your[j].face=input[i];
			j+=1;
			facefreq[2]+=1;
		}
		if(input[i]=='C')
		{
			card_your[j].face=input[i];
			j+=1;
			facefreq[3]+=1;
		}
	}
	
	char *tokenPtr = strtok(input," \nSHDC");
	int  i = 0 ;
	while(tokenPtr!=NULL)
	{
		card_your[i].suit = tokenPtr;
		tokenPtr = strtok(NULL," \nSHDC");
		i = i+1;
	}

	int numfreq[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	int allcard[4][13];
	for(int i=0 ; i<4 ; i++)
	{
		for(int j=0 ; j<13 ; j++)
		{
			allcard[i][j] = 0;
		}
	}

	for(int i=0; i< 13; i++ )
	{
		if( strcmp(card_your[i].suit, "A")==0)
		{card_your[i].num = 1;
		 numfreq[0]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][0]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][0]+=1;
			}
			else if( card_your[i].face == 'D')
			{
				allcard[2][0]+=1;
			}
			else if( card_your[i].face == 'C' )
			{
				allcard[3][0]+=1;
			}
		}
		else if( strcmp(card_your[i].suit , "2")==0)
		{card_your[i].num = 2;
		 numfreq[1]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][1]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][1]+=1;
			}
			else if( card_your[i].face=='D')
			{
				allcard[2][1]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][1]+=1;
			}
		}
		else if(strcmp(card_your[i].suit , "3") ==0)
		{card_your[i].num = 3;
		 numfreq[2]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][2]+=1;
			}
			else if( card_your[i].face== 'H')
			{
				allcard[1][2]+=1;
			}
			else if( card_your[i].face == 'D')
			{
				allcard[2][2]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][2]+=1;
			}	
		}
		else if(strcmp(card_your[i].suit, "4")==0)
		{card_your[i].num = 4;
		numfreq[3]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][3]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][3]+=1;
			}
			else if( card_your[i].face == 'D')
			{
				allcard[2][3]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][3]+=1;
			}
		}
		else if(strcmp(card_your[i].suit, "5")==0)
		{card_your[i].num = 5;
		numfreq[4]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][4]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][4]+=1;
			}
			else if( card_your[i].face == 'D')
			{
				allcard[2][4]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][4]+=1;
			}

		}
		else if(strcmp(card_your[i].suit, "6") ==0)
		{card_your[i].num = 6;
		numfreq[5]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][5]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][5]+=1;
			}
			else if( card_your[i].face == 'D')
			{
				allcard[2][5]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][5]+=1;
			}
		}
		else if(strcmp(card_your[i].suit, "7")==0)
		{card_your[i].num = 7;
		numfreq[6]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][6]+=1;
			}
			else if( card_your[i].face=='H')
			{
				allcard[1][6]+=1;
			}
			else if(card_your[i].face=='D')
			{
				allcard[2][6]+=1;
			}
			else if( card_your[i].face=='C')
			{
				allcard[3][6]+=1;
			}
		}
		else if(strcmp(card_your[i].suit, "8")==0) 
		{card_your[i].num = 8;
		numfreq[7]+=1;
			if(	card_your[i].face=='S')
			{
				allcard[0][7]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][7]+=1;
			}
			else if( card_your[i].face=='D')
			{
				allcard[2][7]+=1;
			}
			else if( card_your[i].face=='C')
			{
				allcard[3][7]+=1;
			}
		}
		else if(strcmp(card_your[i].suit, "9")==0)
		{card_your[i].num = 9;
		numfreq[8]+=1;
			if(	card_your[i].face=='S')
			{
				allcard[0][8]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][8]+=1;
			}
			else if( card_your[i].face=='D')
			{
				allcard[2][8]+=1;
			}
			else if( card_your[i].face=='C')
			{
				allcard[3][8]+=1;
			}
		}
		else if(strcmp(card_your[i].suit, "10")==0)
		{card_your[i].num = 10;
		numfreq[9]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][9]+=1;
			}
			else if( card_your[i].face=='H')
			{
				allcard[1][9]+=1;
			}
			else if( card_your[i].face=='D')
			{
				allcard[2][9]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][9]+=1;
			}
		}
		else if(strcmp(card_your[i].suit, "J")==0)
		{card_your[i].num = 11;
		numfreq[10]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][10]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][10]+=1;
			}
			else if( card_your[i].face == 'D')
			{
				allcard[2][10]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][10]+=1;
			}
		}
		else if(strcmp(card_your[i].suit, "Q") == 0)
		{card_your[i].num = 12;
		numfreq[11]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][11]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][11]+=1;
			}
			else if( card_your[i].face == 'D')
			{
				allcard[2][11]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][11]+=1;
			}
		}
		else if(strcmp(card_your[i].suit, "K") == 0)
		{card_your[i].num = 13;
		numfreq[12]+=1;
			if(	card_your[i].face == 'S')
			{
				allcard[0][12]+=1;
			}
			else if( card_your[i].face == 'H')
			{
				allcard[1][12]+=1;
			}
			else if( card_your[i].face=='D')
			{
				allcard[2][12]+=1;
			}
			else if( card_your[i].face == 'C')
			{
				allcard[3][12]+=1;
			}
		}
	
		printf("face[%d] = %c suit[%d] = %s num[%d]=%d\n"
				,i,card_your[i].face,i,card_your[i].suit,i,card_your[i].num);
	}

	printf("---------------------------\n");
	for(int i=0 ; i<4 ; i++)
	{
		for(int j=0 ; j<13 ; j++)
		{
			printf("%d ",allcard[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------\n");

	int out[13]={0,0,0,0,0,0,0,0,0,0,0,0,0}; 	

	for(int i = 0 ; i<4 ; i++)
	{
		for(int j = 0 ; j<10 ; j++)
		{
			if(j<9)
			{	
				if(allcard[i][j]>0 && allcard[i][j+1]>0 && allcard[i][j+2]>0 && allcard[i][j+3]>0 && allcard[i][j+4]>0)
			{
				printf()
			}
		}
		else
		{
			if(allcard[i][j]>0 && allcard[i][j+1]>0 && allcard[i][j+2]>0 && allcard[i][j+3]>0 && allcard[i][0]>0)
			{
				
			}
		}
	}
	}


	int flushfreq[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	flush(numfreq,flushfreq);

	for(int i =0 ; i<13 ; i++)
	{
		printf("num %d : %d\n",i+1,numfreq[i]);
	//	printf("flush %d : %d\n",i+1,flushfreq[i]);
	}
	for(int i =0 ; i<13 ; i++)
	{
	//	printf("num %d : %d\n",i+1,numfreq[i]);
		printf("flush %d : %d\n",i+1,flushfreq[i]);
	}

	printf("Spades : %d\n", facefreq[0]);
	printf("Hearts : %d\n", facefreq[1]);
	printf("Diamonds : %d\n", facefreq[2]);
	printf("Clubs : %d\n", facefreq[3]);

	return 0;
}


void flush(int numfreq[],int flush[])
{	
	for(int i = 0 ; i<10 ; i++)
	{
		if(i<9)
		{
			if(numfreq[i]>0 && numfreq[i+1]>0 && numfreq[i+2]>0 && numfreq[i+3]>0 && numfreq[i+4]>0)
			{
				flush[i]+=1;
			}
		}
		else
		{
			if(numfreq[i]>0 && numfreq[i+1]>0 && numfreq[i+2]>0 && numfreq[i+3]>0 && numfreq[0]>0)
			{
				flush[i]+=1;
			}
		}
	}
}





