#include<stdio.h>
#include<string.h>
void straight(int numfreq[],int flush[]);

int main(){

	struct cards
	{
		char face; // define face
		char *suit;// define suit
		int fnum; // numerize face S:3 H:2 D:1 C:0
		int num; // numerize suit
		int out; // is it out??
		int sf;
		int straight;
		int four;
		int three;
		int pair;
	};
	typedef struct cards cards;
	char input[80];
	int j=0;
	int dum =0 ;

	fgets(input,80,stdin);
//	printf("input is %s \n",input);
	cards card_your[13];

	int facefreq[4]={0,0,0,0}; 			// face freq [0]:C [1]:D [2]:H [3]:S

	// input card_your.face, card_your.fnum, and counting facefreq
	for(int i=0; i<strlen(input); i++)
	{
		if(input[i]=='S')
		{
			card_your[j].face=input[i];
			card_your[j].fnum=3;
			j+=1;
			facefreq[3]+=1;
		}
		if(input[i]=='H')
		{
			card_your[j].face=input[i];
			card_your[j].fnum=2;
			j+=1;
			facefreq[2]+=1;
		}	
		if(input[i]=='D')
		{
			card_your[j].face=input[i];
			card_your[j].fnum=1;
			j+=1;
			facefreq[1]+=1;
		}
		if(input[i]=='C')
		{
			card_your[j].face=input[i];
			card_your[j].fnum=0;
			j+=1;
			facefreq[0]+=1;
		}
	}
	
	// input card_your.suit
	char *tokenPtr = strtok(input," \nSHDC");
	int  i = 0 ;
	while(tokenPtr!=NULL)
	{
		card_your[i].suit = tokenPtr;
		tokenPtr = strtok(NULL," \nSHDC");
		i = i+1;
	}

	// input card_your.num, and counting num freq
	int numfreq[13]={0,0,0,0,0,0,0,0,0,0,0,0,0}; // num freq
	
	for(int i=0; i< 13; i++ )
	{
		if( strcmp(card_your[i].suit, "A")==0)
		{card_your[i].num = 1;
		 numfreq[0]+=1;}
		else if( strcmp(card_your[i].suit , "2")==0)
		{card_your[i].num = 2;
		 numfreq[1]+=1;}
		else if(strcmp(card_your[i].suit , "3") ==0)
		{card_your[i].num = 3;
		 numfreq[2]+=1;}
		else if(strcmp(card_your[i].suit , "4") ==0)
		{card_your[i].num = 4;
		 numfreq[3]+=1;}
		else if(strcmp(card_your[i].suit , "5") ==0)
		{card_your[i].num = 5;
		 numfreq[4]+=1;}
		else if(strcmp(card_your[i].suit , "6") ==0)
		{card_your[i].num = 6;
		 numfreq[5]+=1;}
		else if(strcmp(card_your[i].suit , "7") ==0)
		{card_your[i].num = 7;
		 numfreq[6]+=1;}
		else if(strcmp(card_your[i].suit , "8") ==0)
		{card_your[i].num = 8;
		 numfreq[7]+=1;}
		else if(strcmp(card_your[i].suit , "9") ==0)
		{card_your[i].num = 9;
		 numfreq[8]+=1;}
		else if(strcmp(card_your[i].suit , "10") ==0)
		{card_your[i].num = 10;
		 numfreq[9]+=1;}
		else if(strcmp(card_your[i].suit , "J") ==0)
		{card_your[i].num = 11;
		 numfreq[10]+=1;}
		else if(strcmp(card_your[i].suit , "Q") ==0)
		{card_your[i].num = 12;
		 numfreq[11]+=1;}
		else if(strcmp(card_your[i].suit , "K") ==0)
		{card_your[i].num = 13;
		 numfreq[12]+=1;}

//	printf("face[%d] = %c suit[%d] = %s num[%d]=%d\n"
//				,i,card_your[i].face,i,card_your[i].suit,i,card_your[i].num);
	}

	// iniialize out with 0
	for(int i=0 ; i<13; i++)
	{
		card_your[i].out=0;
		card_your[i].sf=0;
		card_your[i].straight=0;
		card_your[i].four=0;
		card_your[i].three=0;
		card_your[i].pair=0;
	}

// printf("range: \n");
	// range it from 1 to 13
	for(int i=0 ; i<13 ; i++)
	{
		for(int j=0; j<13 ; j++)
		{
			cards hold = card_your[j];
			int	comj = card_your[j].num;
			int comj1 = card_your[j+1].num;
			if(comj==1)
			{
				comj=14;
			}
			if(comj == 2)
			{
				comj=15;
			}
			if(comj1==1)
			{
				comj1=14;

			}
			if(comj1 == 2)
			{
				comj1=15;
			}
			if(comj > comj1)
			{
				card_your[j]=card_your[j+1];
				card_your[j+1]=hold;
			}
			if(comj == comj1 && card_your[j].fnum > card_your[j+1].fnum )
			{
				card_your[j]=card_your[j+1];
				card_your[j+1]=hold;
			}
		}
/*		for(int k=0 ; k<13; k++)
		{
			printf("%d ",card_your[k].num);
		}
		printf("\n");*/
	}

/*	printf("---------------------------------\n");
	for(int i=0; i<13; i++)
	{
		printf("face[%d] = %c suit[%d] = %s num[%d] = %d out[%d] = %d\n"
				,i,card_your[i].face,i,card_your[i].suit,i,card_your[i].num,i,card_your[i].out);
	}
	printf("---------------------------------\n");
*/	
// straight detection
	int straightfreq[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	straight(numfreq,straightfreq);
	
//	printf("straightfreq : ");
	for(int i=0; i<13 ; i++)
	{
		if(straightfreq[i]>0 )
		{
			if(i+1 != 10)
			{
				for(int j=0 ; j<13; j++)
				{
					if(card_your[j].num==i+1 || 
						card_your[j].num == i+2 || 
						card_your[j].num == i+3 ||
						card_your[j].num == i+4 ||
						card_your[j].num == i+5 )
					{
						if(card_your[j].out == 0)
						{
							card_your[j].straight = 1;
						}
					}
				}
			}
			else if( i+1 == 10)
			{
					if(card_your[j].num==i+1 || 
						card_your[j].num == i+2 || 
						card_your[j].num == i+3 ||
						card_your[j].num == i+4 ||
						card_your[j].num == 1 ||
						card_your[j].out == 0
						)
					{
						card_your[j].straight = 1;
					}

			}

		}
//		printf("%d ",straightfreq[i]);
	}
//	printf("\n");

// straight flush detection : creating sfele to 
	int sfele[10][5];

	for(int i=0; i<10 ; i++)
	{
		for(int j=0; j<5 ; j++)
		{
			sfele[i][j]=0;
		}
	}
	
	int sfn =0;

	for(int i=0; i<4 ; i++)
	{
		if(facefreq[i]>4)
		{
			for(int j = 12; j>=0 ; j--)
			{
				if(card_your[j].fnum == i && straightfreq[card_your[j].num-1] == 1)
				{
					if(card_your[j].num<10)
					{
						int hold_sf[5]={-1,-1,-1,-1,-1};
						hold_sf[0]=j;
						for(int l=0; l<13 ;l++)
						{
							for(int k=0; k<5; k++)
							{
								if(card_your[l].num==card_your[j].num+k && card_your[l].fnum==i)
								{
									hold_sf[k]=l;
								//	printf("l : %d ",l);
								}
							}
						}				

						if(hold_sf[1]>=0 && hold_sf[2]>=0 && hold_sf[3]>=0 && hold_sf[4]>=0 )
						{
							for(int k=0; k<5 ; k++)
							{
								sfele[sfn][k]=hold_sf[k];
							}
							sfn+=1;
						}
					}
					else
					{
						int hold_sf[5]={-1,-1,-1,-1,-1};
						hold_sf[0]=j;
						for(int l=0; l<13 ;l++)
						{
							for(int k=0; k<4; k++)
							{
								if(card_your[l].num==card_your[j].num+k && card_your[l].fnum==i)
								{
									hold_sf[k]=l;
								//	printf("l : %d ",l);
								}
							}
							if(card_your[l].num==1 && card_your[l].fnum==i)
							{
								hold_sf[4]=l;
							}

						}
						if(hold_sf[1]>=0 && hold_sf[2]>=0 && hold_sf[3]>=0 && hold_sf[4]>=0 )
						{
							for(int k=0; k<5 ; k++)
							{
								sfele[sfn][k]=hold_sf[k];
								card_your[sfele[sfn][k]].sf = 1;
							}
							sfn+=1;
						}

					}
						
				}
				
			}
		
		}

	}

/*	printf("sfele : \n");	
	for(int i=0; i<sfn ; i++)
	{
		for(int j=0; j<5;j++)
		{
			printf("%d ", sfele[i][j]);
		}
		printf("\n");
	}*/	
// detect the  four, three, pair
	for(int i=0 ; i<13 ; i++)
	{
		if(numfreq[i] >= 2)
		{
			for(int j=0 ; j<13 ; j++)
			{
				if(card_your[j].num == i+1)
				{
					card_your[j].pair =1 ;
				}
			}
		}else if(numfreq[i] >= 3)
		{
				if(card_your[j].num == i+1)
				{
					card_your[j].three =1 ;
				}

		}else if(numfreq[i] == 4)
		{
				if(card_your[j].num == i+1)
				{
					card_your[j].four =1 ;
				}
		}
	}


// sf > four of a kind > full house > straight >  pair > single

// out : sf
	for(int i=0 ; i<sfn; i++)
	{
		if(card_your[sfele[i][0]].out ==0 &&
			card_your[sfele[i][1]].out ==0 &&
			card_your[sfele[i][2]].out ==0 &&
			card_your[sfele[i][3]].out ==0 &&
			card_your[sfele[i][4]].out ==0			
				)
		{
			for(int j=0; j<5; j++)
			{
				printf("%c%s ",card_your[sfele[i][j]].face,card_your[sfele[i][j]].suit);
				card_your[sfele[i][j]].out=1;
			}
			printf("\n");
		}	
	}

	// renew numfreq
	for(int i=0 ; i<13 ; i++)
	{
		numfreq[i]=0;
		for( int j=0 ; j<13 ; j++)
		{
			if(card_your[j].num==i+1 && card_your[j].out==0)
			{ 
				numfreq[i]+=1;
			}
		}
	}

	// straight detection again
	for(int i=0; i<13 ; i++)
	{
		straightfreq[i]=0;
	}
	straight(numfreq,straightfreq);
	
//	printf("straightfreq again: ");
	for(int i=0; i<13 ; i++)
	{
		if(straightfreq[i]>0 )
		{
			if(i+1 != 10)
			{
				for(int j=0 ; j<13; j++)
				{
					if(card_your[j].num==i+1 || 
						card_your[j].num == i+2 || 
						card_your[j].num == i+3 ||
						card_your[j].num == i+4 ||
						card_your[j].num == i+5)
					{
						if(card_your[j].out == 0)
						{card_your[j].straight = 1;}
					}
				}
			}
			else if( i+1 == 10)
			{
					if(card_your[j].num==i+1 || 
						card_your[j].num == i+2 || 
						card_your[j].num == i+3 ||
						card_your[j].num == i+4 ||
						card_your[j].num == 1)
					{
						if(card_your[j].out ==0)
						{
							card_your[j].straight = 1;
						}
					}
			}

		}
//		printf("%d ",straightfreq[i]);
	}
//	printf("\n");

	// detect the  four, three, pair again
	for(int i=0 ; i<13 ; i++)
	{
		if(numfreq[i] >= 2)
		{
			for(int j=0 ; j<13 ; j++)
			{
				if(card_your[j].num == i+1 && card_your[j].out == 0)
				{
					card_your[j].pair =1 ;
				}
			}
		}else if(numfreq[i] >= 3)
		{
				if(card_your[j].num == i+1 && card_your[j].out == 0)
				{
					card_your[j].three =1 ;
				}

		}else if(numfreq[i] == 4)
		{
				if(card_your[j].num == i+1 && card_your[j].out == 0)
				{
					card_your[j].four =1 ;
				}
		}
	}

	
// out : four of a kind
	for( int i=12 ; i>=0 ; i--)
	{
		if(numfreq[i]==4)
		{
			dum =0;
			for(int j=0 ; j<13 ; j++)
			{
				if(card_your[j].num==i+1)
				{
					printf("%c%s ",card_your[j].face,card_your[j].suit);
					card_your[j].out=1;
				}
			}
			for(int k=0; k<13 ; k++)
			{
				if(card_your[k].straight+card_your[k].four+card_your[k].three+card_your[k].pair==0 && card_your[k].out == 0 && dum==0)
				{
					dum+=1;
					printf("%c%s ",card_your[k].face,card_your[k].suit);
					card_your[k].out=1;
				}
			}
			for(int k=0; k<13 ; k++)
			{
				if(card_your[k].straight+card_your[k].four+card_your[k].three==0 && card_your[k].out == 0 && dum==0)
				{
					dum+=1;
					printf("%c%s ",card_your[k].face,card_your[k].suit);
					card_your[k].out=1;
				}
			}

			printf("\n");
		}
	}

// renew numfreq
	for(int i=0 ; i<13 ; i++)
	{
		numfreq[i]=0;
		for( int j=0 ; j<13 ; j++)
		{
			if(card_your[j].num==i+1 && card_your[j].out==0)
			{ 
				numfreq[i]+=1;
			}
		}
	}

	// straight detection again
	for(int i=0; i<13 ; i++)
	{
		straightfreq[i]=0;
	}
	straight(numfreq,straightfreq);
	
//	printf("straightfreq again: ");
	for(int i=0; i<13 ; i++)
	{
		if(straightfreq[i]>0 )
		{
			if(i+1 != 10)
			{
				for(int j=0 ; j<13; j++)
				{
					if(card_your[j].num==i+1 || 
						card_your[j].num == i+2 || 
						card_your[j].num == i+3 ||
						card_your[j].num == i+4 ||
						card_your[j].num == i+5)
					{
						if(card_your[j].out == 0)
						{card_your[j].straight = 1;}
					}
				}
			}
			else if( i+1 == 10)
			{
					if(card_your[j].num==i+1 || 
						card_your[j].num == i+2 || 
						card_your[j].num == i+3 ||
						card_your[j].num == i+4 ||
						card_your[j].num == 1)
					{
						if(card_your[j].out ==0)
						{
							card_your[j].straight = 1;
						}
					}
			}

		}
//		printf("%d ",straightfreq[i]);
	}
//	printf("\n");

	// detect the three, pair again
	for(int i=0 ; i<13 ; i++)
	{
		if(numfreq[i] >= 2)
		{
			for(int j=0 ; j<13 ; j++)
			{
				if(card_your[j].num == i+1 && card_your[j].out == 0)
				{
					card_your[j].pair =1 ;
				}
			}
		}else if(numfreq[i] >= 3)
		{
				if(card_your[j].num == i+1 && card_your[j].out == 0)
				{
					card_your[j].three =1 ;
				}

		}
	}

//out full house
//int dum2 =0;
	for( int i=0 ; i<13 ; i++)
	{
		if(numfreq[i]==3)
		{
			dum = 0;
			for(int k=2; k<13 ; k++)
			{
				if(numfreq[k]==2)
				{
					for(int j=2;  j<13 ; j++)
					{	
						if(card_your[j].num==i+1 && card_your[j].out==0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
						}
					}
					for(int l=0; l<13 ; l++)
					{
						if(card_your[l].num==k+1 && card_your[l].out == 0 && dum <2)
						{
							printf("%c%s ",card_your[l].face,card_your[l].suit);
							card_your[l].out=1;
							dum+=1;
							if(dum==2){printf("\n");}
						}
					}
				}
			}
			for(int k=0; k<2 ; k++)
			{
				if(numfreq[k]==2)
				{
					for(int j=0 ; j<13 ; j++)
					{	
						if(card_your[j].num==i+1 && card_your[j].out==0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
						}
					}
					for(int l=0; l<13 ; l++)
					{
						if(card_your[l].num==k+1 && card_your[l].out == 0 && dum <2)
						{
							printf("%c%s ",card_your[l].face,card_your[l].suit);
							card_your[l].out=1;
							dum+=1;
							if(dum==2){printf("\n");}
						}
					}
				}
			}
		}
	}
// renew numfreq
	for(int i=0 ; i<13 ; i++)
	{
		numfreq[i]=0;
		for( int j=0 ; j<13 ; j++)
		{
			if(card_your[j].num==i+1 && card_your[j].out==0)
			{ 
				numfreq[i]+=1;
			}
		}
	}


	// straight detection and outagain
	for(int i=0; i<13 ; i++)
	{
		straightfreq[i]=0;
	}
	straight(numfreq,straightfreq);
	
//	printf("straightfreq again: ");
int starr[5] = {0,0,0,0,0};
	for(int i=1; i>=0 ; i--)
	{
		if(straightfreq[i]>0 )
		{
			for(int f = 0 ; f < 5 ; f++)
			{
				starr[f]=0;
			}
			if(i+1 != 10)
			{
				for(int j=0 ; j<13; j++)
				{

					if(card_your[j].num==i+1 && starr[0] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[0]=1;
						}
					}
					else if(card_your[j].num==i+2 && starr[1] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[1]=1;
						}
					}
					else if(card_your[j].num==i+3 && starr[2] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[2]=1;
						}
					}
					else if(card_your[j].num==i+4 && starr[3] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[3]=1;
						}
					}
					else if(card_your[j].num==i+5 && starr[4] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[4]=1;
						}
					}
				}
			}
			else if( i+1 == 10)
			{
				for(int j=0 ; j<13; j++)
				{

					if(card_your[j].num==i+1 && starr[0] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[0]=1;
						}
					}
					else if(card_your[j].num==i+2 && starr[1] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[1]=1;
						}
					}
					else if(card_your[j].num==i+3 && starr[2] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[2]=1;
						}
					}
					else if(card_your[j].num==i+4 && starr[3] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[3]=1;
						}
					}
					else if(card_your[j].num==i+5 && starr[4] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[4]=1;
						}
					}
				}
			}
			printf("\n");	
		}
	}

	for(int i=13; i>=2 ; i--)
	{
		if(straightfreq[i]>0 )
		{
			for(int f = 0 ; f < 5 ; f++)
			{
				starr[f]=0;
			}
			if(i+1 != 10)
			{
				for(int j=0 ; j<13; j++)
				{

					if(card_your[j].num==i+1 && starr[0] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[0]=1;
						}
					}
					else if(card_your[j].num==i+2 && starr[1] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[1]=1;
						}
					}
					else if(card_your[j].num==i+3 && starr[2] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[2]=1;
						}
					}
					else if(card_your[j].num==i+4 && starr[3] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[3]=1;
						}
					}
					else if(card_your[j].num==i+5 && starr[4] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[4]=1;
						}
					}
				}
			}
			else if( i+1 == 10)
			{
				for(int j=0 ; j<13; j++)
				{

					if(card_your[j].num==i+1 && starr[0] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[0]=1;
						}
					}
					else if(card_your[j].num==i+2 && starr[1] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[1]=1;
						}
					}
					else if(card_your[j].num==i+3 && starr[2] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[2]=1;
						}
					}
					else if(card_your[j].num==i+4 && starr[3] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[3]=1;
						}
					}
					else if(card_your[j].num==i+5 && starr[4] == 0)
					{
						if(card_your[j].out == 0)
						{
							printf("%c%s ",card_your[j].face,card_your[j].suit);
							card_your[j].out=1;
							starr[4]=1;
						}
					}
				}
			}
			printf("\n");	
		}
	}

	// detect pair again
	for(int i=1 ; i>=0 ; i--)
	{
		if(numfreq[i] >= 2)
		{
			dum = 0;
			for(int j=13 ; j>=0 ; j--)
			{
				if(card_your[j].num == i+1 && card_your[j].out == 0 && dum <= 0)
				{
					card_your[j].pair =1 ;
					printf("%c%s ",card_your[j].face,card_your[j].suit);
					card_your[j].out=1;
					for(int k = 0; k<13 ; k++)
					{
						if(card_your[k].num == i+1 && card_your[k].out == 0 && dum <=0)
						{
							card_your[k].pair =1 ;
							printf("%c%s ",card_your[k].face,card_your[k].suit);
							card_your[k].out=1;
							dum +=1 ;
						}
					}
				printf("\n");
				}
			}
		}
	}



	for(int i=13 ; i>=2 ; i--)
	{
		if(numfreq[i] >= 2)
		{
			dum = 0;
			for(int j=13 ; j>=0 ; j--)
			{
				if(card_your[j].num == i+1 && card_your[j].out == 0 && dum <= 0)
				{
					card_your[j].pair =1 ;
					printf("%c%s ",card_your[j].face,card_your[j].suit);
					card_your[j].out=1;
					for(int k = 0; k<13 ; k++)
					{
						if(card_your[k].num == i+1 && card_your[k].out == 0 && dum <=0)
						{
							card_your[k].pair =1 ;
							printf("%c%s ",card_your[k].face,card_your[k].suit);
							card_your[k].out=1;
							dum +=1 ;
						}
					}
				printf("\n");
				}
			}
		}
	}

	for(int j=13 ; j>=0 ; j--)
	{
		if(card_your[j].out == 0)
		{
			printf("%c%s ",card_your[j].face,card_your[j].suit);
			printf("\n");
		}
	}

/*
// printing testing
	printf("---------------------------\n");
	for(int i=0 ; i<10; i++)
	{
		for(int j=0; j<5; j++)
		{
			printf("%d ",sfele[i][j]);
		}
		printf("\n");
	}	
	
	printf("---------------------------\n");

	printf("---------------------------\n");
	for(int i=0 ; i<sfn; i++)
	{
		for(int j=0; j<5; j++)
		{
			printf("%c%s ",card_your[sfele[i][j]].face,card_your[sfele[i][j]].suit);
		}
		printf("\n");
	}	
	printf("---------------------------\n");
*/
	return 0;
}

void straight(int numfreq[],int flush[])
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

