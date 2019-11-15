#include<stdio.h>

int main()
{
	int turn,n;
	for(n=1;n<4;n++)
	{
		while(1)
		{
			while(turn!=0);
				printf("\nI am Process-1 and I am in Critical section");
			turn=1;
				printf("\nI am Process-1 and I am in Remainder section");
			break;
		}
		while(1)
		{
			while(turn!=1);
				printf("\nI am Process-2 and I am in Critical section");
			turn=0;
				printf("\nI am Process-2 and I am in Remainder section");
			break;	
		}	
	}
return 0;	
}
