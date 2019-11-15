#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
	int turn=0, flag[2];

void *First( )
{	
	while(1)
	{
		flag[0]=1;
		turn=1;
		while(turn==1 && flag[1]==1);
		printf("P1 is executing\n");
		printf("P2 is waiting\n");
		printf("-----------------\n");
		flag[0]=0;
		sleep(1);
	}
}
void *Second( )
{	
	while(1)
	{
		flag[1]=1;
		turn=0;
		while(turn==0 && flag[0]==1);
		printf("P2 is executing\n");
		printf("P1 is waiting\n");
		printf("------------------\n");
		flag[1]=0;
		sleep(1);
	}
}
int main()
{

	pthread_t thread1,thread2;
	printf("Peterson Solution\n\n");
	pthread_create(&thread1,NULL,First,NULL);
	pthread_create(&thread2,NULL,Second,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	exit(0);
}
