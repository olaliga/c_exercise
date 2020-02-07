#include <stdio.h>
#include <stdlib.h>


int main() {
	
	const char *string = "51.2% are admitted"; // initialize string
	char *stringPtr; // create char pointer
	double d; 
	int a = 1;
	int *ptr;
	ptr=&a;
	//printf("ptr(d) %d\n",ptr);
	printf("ptr(p) %p\n",ptr);
	printf("*ptr %d\n",*ptr);
	printf("_____________ \n");

	d	= strtod(string,&stringPtr);	
	printf("The string \"%s\" is converted to the\n", string);
	printf("double value %.2f and the string \"%s\"\n", d, stringPtr);

	//printf("*stringPtr %s\n",*stringPtr);
	printf("&stringPtr %p\n",&stringPtr);
	printf("stringPtr(p) %p\n",stringPtr);
	printf("stringPtr(s) %s\n",stringPtr);
	printf("&string %p\n",&string);

	return 0;
}
