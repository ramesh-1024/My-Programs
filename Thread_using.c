#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
	int turn=0;

void First( )
{	
	while(1)
	{
		while(turn!=0);
		printf("P1 is executing..\n");
		printf("P2 is waiting...\n");
		printf("-----------------\n");
		turn=1;
		sleep(2);
	}
}
void Second( )
{	
	while(1)
	{
		while(turn!=1);
		printf("P2 is executing..\n");
		printf("P1 is waiting...\n");
		printf("-----------------\n");
		turn=0;
		sleep(2);
	}
}


int main()
{

	pthread_t thread1,thread2;
	printf("Strict Alternate Solution\n\n");
	pthread_create(&thread1,NULL,First,NULL);
	pthread_create(&thread2,NULL,Second,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	exit(0);
}
