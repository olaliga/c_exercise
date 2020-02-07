#include <stdio.h>


int chartorownum(char a);
const int size = 8;
void change(int pos, int dir, int rndptr,int chptr, int numchessrow, int numchesscol, int *score_b, int *score_w, int board[size][size]);
void holdboardfcn(int hold_b[size][size], int board_b[size][size]);


int main() {
/*initialize borad game with pointer white and black chess*/
	
	char chessrow;
	int chesscol;
	int b;
	int *bptr;
	int w;	
	int *wptr;
	int board[size][size];
	int score_b;
	int score_w;
	int hold_b;
	int hold_w;
	int round;
	int error;

	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			board[i][j]=0;
		}
	}

	b=1;
	bptr=&b;
	w=2;
	wptr=&w;
	board[3][3]=*wptr;
	board[4][4]=*wptr;
	board[3][4]=*bptr;
	board[4][3]=*bptr;
	score_b=2;
	score_w=2;
	round = 1;
	error = 0;

	while(scanf("%c %d\n",&chessrow, &chesscol) != EOF)
	{	
		int numchessrow;
		int numchesscol;

		numchesscol = chartorownum(chessrow);
		numchessrow = chesscol-1;
	/*	printf("chessrow %d chesscol %d\n",numchessrow, numchesscol);*/

		if( numchesscol<0 || numchesscol>7)
		{
			printf("INVALID MOVE AT %c %d\n",chessrow,chesscol);
			error +=1;
			break;
		}
		else if(numchessrow<0 || numchessrow>7)
		{
			printf("INVALID MOVE AT %c %d\n",chessrow,chesscol);
			error +=1;
			break;
		}

		if(board[numchessrow][numchesscol]!=0)
		{
			printf("INVALID MOVE AT %c %d\n",chessrow,chesscol);
			error +=1 ;
			break;

		}

		if(round%2==1)
		{	
			score_b +=1;
			hold_b=score_b;
			hold_w=score_w;
			board[numchessrow][numchesscol]=*bptr;
			
		/*	printf("start\n");
			for(int i=0; i<8; i++)
			{
				for(int j=0; j<8; j++)
				{
					printf("%d ",board[i][j]);
				}	
				printf("\n");
			}
			printf("_____________________________\n");
		*/
			change(1,1,*bptr,*wptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(-1,1,*bptr,*wptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(1,2,*bptr,*wptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(-1,2,*bptr,*wptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(1,3,*bptr,*wptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(-1,3,*bptr,*wptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(1,4,*bptr,*wptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(-1,4,*bptr,*wptr,numchessrow,numchesscol, &score_b, &score_w, board);

			if(score_b==hold_b && score_w==hold_w)
			{
				error += 1;
				printf("INVALID MOVE AT %c %d\n",chessrow,chesscol);
				break;
			}
		}	
		else
		{
			score_w +=1 ;
			hold_b=score_b;
			hold_w=score_w;
			board[numchessrow][numchesscol]=*wptr;
		/*	
			printf("start\n");
			for(int i=0; i<8; i++)
			{
				for(int j=0; j<8; j++)
				{
					printf("%d ",board[i][j]);
				}	
				printf("\n");
			}
			printf("_____________________________\n");
		*/
			change(1,1,*wptr,*bptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(-1,1,*wptr,*bptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(1,2,*wptr,*bptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(-1,2,*wptr,*bptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(1,3,*wptr,*bptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(-1,3,*wptr,*bptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(1,4,*wptr,*bptr,numchessrow,numchesscol, &score_b, &score_w, board);
			change(-1,4,*wptr,*bptr,numchessrow,numchesscol, &score_b, &score_w, board);

			if(score_b==hold_b && score_w==hold_w)
			{
				error +=1;
				printf("INVALID MOVE AT %c %d\n",chessrow,chesscol);
				break;
			}

		}		
		round+=1;
/*
		printf("finish\n");
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				printf("%d ",board[i][j]);
			}
			printf("\n");
		}
		printf("5 score_b is %d\n",score_b);
		printf("6 score_w is %d\n",score_w);
		printf("_____________________________\n");*/
	}
	
	if(error == 0)
	{
		printf("%d:%d\n",score_b,score_w);
		if(score_b > score_w){printf("Black wins!\n");}else{printf("White wins!\n");}
	}
	return 0;
}


int chartorownum(char a)
{
	char array[]={'A','B','C','D','E','F','G','H'};
	int i=0;
	while(a!=array[i]){i++;}
  	return i;	
}

void holdboardfcn(int hold_b[size][size], int board_b[size][size])
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			hold_b[i][j]=board_b[i][j];
		}
	}
}

void change(int pos, int dir, int rndptr,int chptr, int numchessrow, int numchesscol, int *score_b, int *score_w, int board[size][size])
{	
	int holdboard[size][size];
	int holdscore_b;
	int holdscore_w;

	if(dir == 1)
	{
		holdboardfcn(holdboard, board);
		holdscore_b = *score_b;
		holdscore_w = *score_w;

		while(numchesscol >= 0 && numchesscol <= 7 && numchessrow >= 0 && numchessrow <= 7)
		{
			numchessrow = numchessrow+1*pos;
			if(numchessrow <= 7 && numchessrow >= 0)
			{
				if(board[numchessrow][numchesscol] == chptr)
				{	
					board[numchessrow][numchesscol] = rndptr;
					if(	rndptr ==1 ){*score_b += 1;*score_w -=1;}else{*score_b -= 1;*score_w += 1;}
				}
				else if(board[numchessrow][numchesscol]==rndptr){break;}	
				else
				{
					holdboardfcn(board, holdboard);
					*score_b = holdscore_b;
					*score_w = holdscore_w;
					break;
				}	
			}	
			else
			{
				holdboardfcn(board, holdboard);
				*score_b = holdscore_b;
				*score_w = holdscore_w;
				break;
			}	
		}		
	}
	else if (dir == 2)
	{	
		holdboardfcn(holdboard, board);
		holdscore_b = *score_b;
		holdscore_w = *score_w;

		while(numchesscol >= 0 && numchesscol <= 7 && numchessrow >= 0 && numchessrow <= 7)
		{
			numchesscol = numchesscol+1*pos;
			if(numchesscol <= 7 && numchesscol>=0)
			{
				if(board[numchessrow][numchesscol] == chptr)
				{	
					board[numchessrow][numchesscol] = rndptr;
					if( rndptr ==1 ){*score_b +=1;*score_w -=1;}else{*score_b -=1;*score_w +=1;}
				}	
				else if(board[numchessrow][numchesscol]==rndptr){break;}	
				else
				{
					holdboardfcn(board, holdboard);
					*score_b = holdscore_b;
					*score_w = holdscore_w;
					break;
				}	
			}
			else
			{
				holdboardfcn(board, holdboard);
				*score_b = holdscore_b;
				*score_w = holdscore_w;
				break;
			}	
		}	
	}	
	else if (dir == 3)
	{
		holdboardfcn(holdboard, board);
		holdscore_b = *score_b;
		holdscore_w = *score_w;

		while(numchesscol >= 0 && numchesscol <= 7 && numchessrow >= 0 && numchessrow <= 7)
		{
			numchesscol = numchesscol+1*pos;
			numchessrow = numchessrow+1*pos;	
			if(numchesscol <= 7 && numchesscol>=0 && numchessrow <=7 && numchessrow >=0)
			{
				if(board[numchessrow][numchesscol] == chptr)
				{	
					board[numchessrow][numchesscol] = rndptr;
					if( rndptr ==1 ){*score_b +=1;*score_w -=1;}else{*score_b -=1;*score_w +=1;}
				}
				else if(board[numchessrow][numchesscol]==rndptr){break;}	
				else
				{
					holdboardfcn(board, holdboard);
					*score_b = holdscore_b;
					*score_w = holdscore_w;
					break;
				}	
			}
			else
			{
				holdboardfcn(board, holdboard);
				*score_b = holdscore_b;
				*score_w = holdscore_w;
				break;
			}	
		}
	}	
	else
	{
		holdboardfcn(holdboard, board);
		holdscore_b = *score_b;
		holdscore_w = *score_w;

		while(numchesscol >= 0 && numchesscol <= 7 && numchessrow >= 0 && numchessrow <= 7)
		{
			numchesscol = numchesscol+1*pos;
			numchessrow = numchessrow-1*pos;
			if(numchesscol <= 7 && numchesscol>=0 && numchessrow <=7 && numchessrow >=0)
			{
				if(board[numchessrow][numchesscol] == chptr)
				{	
					board[numchessrow][numchesscol] = rndptr;
					if( rndptr ==1 ){*score_b +=1;*score_w -=1;}else{*score_b -=1;*score_w +=1;}
				}
				else if(board[numchessrow][numchesscol]==rndptr){break;}	
				else
				{
					holdboardfcn(board, holdboard);
					*score_b = holdscore_b;
					*score_w = holdscore_w;
					break;
				}		
			}
			else
			{
				holdboardfcn(board, holdboard);
				*score_b = holdscore_b;
				*score_w = holdscore_w;
				break;
			}	
		}
	}	
}
	

