#include <stdio.h>
#include <ctype.h>
#include <string.h>
char *lower(char string[]);


int main() {
	char sentence[100000];// initialize sentence pointer 
	fgets(sentence,100000,stdin);

	/*non-alphanumerical characters using ascii*/
	static char delims[256]; /* this is oversized */
	int i;
    int j = 0;
    for (i = 1; i<256; i++)
    {
        if (!isalnum(i))
		{
            delims[j++] = i;
		}
    }
    delims[j] = 0;/* this is unnecessary as statics are initialised to zero */	

	char *tokenPtr = strtok(sentence, delims); // begin tokenizing sentence
	char dict[1001][50];
	int freq[1001];
	for(int i=0; i<1001; i++)
	{
		freq[i]=0;
	}

	while(tokenPtr != NULL)
	{	
		int i = 0;
		while(strcasecmp(dict[i],tokenPtr)!=0)
		{	
			if(strcasecmp(dict[i],dict[1000])==0)
			{
				sprintf(dict[i],"%s",lower(tokenPtr));
				break;
			}
			i++;
		}
		freq[i]+=1;
		tokenPtr = strtok(NULL,delims);
	}
	
	i = 0;
	while(strcasecmp(dict[i],dict[1000]) != 0)
	{
		printf("%s ",dict[i]);
		printf("%d\n",freq[i]);
		i++;
	}	
	return 0;
}

char *lower(char string[])
{
	for(int i=0;i<strlen(string);i++)
	{
		string[i]=tolower(string[i]);
	}
	return string;
}
