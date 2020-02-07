#include <stdio.h>

long long int gcd(long long int, long long int);

int main() {
	int num;
	int i;
	long long int first;
	long long int need;
	long long int lcm;

	i = 0;
	scanf("%d",&num);
	while(i<num){
		if(i==0)
		{
			scanf("%lld",&first);
			lcm = first;
		}
		else
		{
			scanf("%lld",&need);
			lcm = need*lcm/gcd(lcm,need);
		}
		i++;	
	}
	printf("%lld\n",lcm);
	return 0;
}

long long int gcd(long long int a, long long int b) {
	int r = 0;
	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
