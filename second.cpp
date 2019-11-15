#include<stdio.h>
int main()
{
	int n=0,i,j,ref[30],fnum,hit=0,fault=0,pointer=0;
	printf("enter reference string length\n" );
	scanf("%d",&n);
	for ( i = 0; i <n; ++i)
		scanf("%d",&ref[i]);
	printf("enter no.of frames\n");
	scanf("%d",&fnum);
	int frames[fnum],s[fnum];
	for(j=0;j<fnum;++j)
	{
		s[j]=-1;
		frames[j]=-1;
	}
	for (i = 0; i < n; ++i)
	{
		for(j=0;j<fnum;++j)
		{
			if (frames[j]==ref[i])
			{
				s[j]=1;
				hit++;
				break;
			}
		}
		if(fnum==j)
		{
			while(s[pointer]==1)
			{
				s[pointer]--;
				if(pointer==fnum)
					pointer=0;
			}
			if(s[pointer]==-1)
				s[pointer]=0;
			frames[pointer]=ref[i];
			if(pointer==fnum)
				pointer=0;
			fault++;
		}
		for(j=0;j<fnum;j++)
		printf("%d    %d\n",frames[j],s[j] );
	}
	printf("hits=%d  faults=%d\n",hit,fault );
return 0;
}
