#include <stdio.h>

int main() {
	int num;
	int now;
	long long input;
	long long big;
	


	now=0;
	scanf("%d",&num);	
	while(now<num){
		input=1;
		big=0;
		while(input!=0){
			scanf("%lld",&input);
			if(input>=big){
				big=input;
			}
		}
		printf("%lld\n",big);	
		now++;
	}
	return 0;
}
