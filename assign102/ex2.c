#include <stdio.h>

int main() {
	float num;
	int philip;
	int other;
	float now;
	float win;
	float rate;

	now=0;
	win=0;
	scanf("%f",&num);
	while(now<num){
		scanf("%d %d",&philip,&other);
			if(philip==1){
				if(other==3){
				win++;
				}
			}
			if(philip==2){
				if(other==1){
				win++;
				}
			}
			if(philip==3){
				if(other==2){
				win++;
				}
			}
		now++;
		}		
	rate = 100*win/num;
	printf("Philip wins %.0f times.\n",win);
	printf("Win rate %.1f%%.\n",rate);
	return 0;
}
