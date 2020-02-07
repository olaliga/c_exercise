#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define size 80 

int validfcn(char *colors, const char valid[][size]);
int colorret(char *colors, const char valid[][size]);


int main() {

	char input[size];
	fgets(input, size, stdin);
//	printf("input is %s\n", input);
	char letterarray[4];
	int numarray[3];
	const char valid[12][size] = 
	{"silver", "gold", "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
	const int resis[12]={-2,-1,0,1,2,3,4,5,6,7,8,9};


	int j=0;
	for(int i=0; i<strlen(input); i++)
	{
		if(isupper(input[i]))
		{	
			letterarray[j]=input[i];
//			printf("letterarray[%d] is %c\n",j, letterarray[j]);
			j++;
		}
	}
	
	
	for(int i=0; i<3 ; i++)
	{
		if(strncmp(&letterarray[i],"A",1)==0)
		{numarray[i]=0;}
		else if(strncmp(&letterarray[i],"B",1)==0)
		{numarray[i]=1;}
		else
		{numarray[i]=2;}
//		printf("numarray[%d] = %d\n",i,numarray[i]);
	}

	char *tokenPtr = strtok(input, "ABC\n"); // begin tokenizing sentence
	char colorarr[3][size];
	strcat(colorarr[numarray[0]],tokenPtr);
	tokenPtr = strtok(NULL, "ABC\n"); // get next token
	strcat(colorarr[numarray[1]],tokenPtr);
	tokenPtr = strtok(NULL, "ABC\n");
	strcat(colorarr[numarray[2]] , tokenPtr);
//	char *color3 = tokenPtr;
/*
	printf("colorarr[%d] = %s\n",0,colorarr[0]);
	printf("colorarr[%d] = %s\n",1,colorarr[1]);
	printf("colorarr[%d] = %s\n",2,colorarr[2]);
*/
/*
	printf("color1 is %s\n", color1);
	printf("color2 is %s\n", color2);
	printf("color3 is %s\n", color3);	
	if(validfcn(color1,valid)==0)
	{printf("%s is valid.\n",color1);}
	else
	{printf("%s is not valid.\n",color1);}	
	if(validfcn(color2,valid)==0)
	{printf("%s is valid.\n",color2);}
	else
	{printf("%s is not valid.\n",color2);}
	if(validfcn(color3,valid)==0)
	{printf("%s is valid.\n",color3);}
	else
	{printf("%s is not valid.\n",color3);}
	*/
	
	if(validfcn(colorarr[0],valid)==1){printf("Invalid color: %s\n",colorarr[0]);}
	else if(validfcn(colorarr[1],valid)==1){printf("Invalid color: %s\n",colorarr[1]);}
	else if(validfcn(colorarr[2],valid)==1){printf("Invalid color: %s\n",colorarr[2]);}
	else if(strcmp(colorarr[0],"silver")==0 || strcmp(colorarr[0],"gold") ==0)
	{
		printf("Invalid color: %s\n",colorarr[0]);
	}
	else if	(strcmp(colorarr[1],"silver")==0 || strcmp(colorarr[1],"gold") ==0)
	{
		printf("Invalid color: %s\n",colorarr[1]);
	}			
	else
	{
	// print Resistance value: 90000.000 ohms
		float resistance = (10*resis[colorret(colorarr[0],valid)]+
			resis[colorret(colorarr[1],valid)])*
			pow(10,resis[colorret(colorarr[2],valid)]);
		printf("Resistance value: %.3f ohms\n",resistance);
	}
	return 0;
}

int validfcn(char *colors, const char valid[][size])
{
	for(int i=0; i<12; i++)
	{	
		if(strcmp(colors,valid[i])==0)
		{
			return 0;
		}
	}
	return 1;
}

int colorret(char *colors, const char valid[][size])
{
	for(int i =0; i<12 ; i++)
	{
		if(strcmp(colors,valid[i])==0)
		{	
			return i;
		}
	}
	return 0;
}
