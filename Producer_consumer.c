#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int mutex=1,empty=4,full=0,x=0;
void signalc(int *s)
{
	*s+=1;
}

void wait(int *m)
{
	while(*m<=0);
	*m=*m-1;
}

 void *prod()
{
	do
	{
		printf("producing\n");
		wait(&empty);
		wait(&mutex);
		++x;
		printf("adding an item=%d\n",x);
		printf("------------\n");
		signalc(&mutex);
		signalc(&full);
		sleep(1);
		
	}while(1);
}
void *cons()
{
	do
	{
		//printf("Removed\n");
		wait(&full);
		wait(&mutex);
		signalc(&mutex);
		signalc(&empty);
	
		printf("consuming an item=%d\n",x);
			--x;
		printf("-------------\n");
		sleep(1);
	}while(1);
}

int main()
{
	pthread_t  p1,p2,p3,consumer;
	printf("Producer-Consumer Problem\n ");
	pthread_create(&p1,NULL,prod,NULL);
//	pthread_create(&p2,NULL,prod,NULL);
	//pthread_create(&p3,NULL,prod,NULL);
	
	pthread_create(&consumer,NULL,cons,NULL);
	pthread_join(p1,NULL);
	//	pthread_join(p2,NULL);
		//	pthread_join(p3,NULL);
	pthread_join(consumer,NULL);
	
	exit(0);
}
