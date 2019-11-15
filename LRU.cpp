#include<stdio.h>
int ref[30],frame[10],n,i,k,j,first,nof,page_hit=0,page_fault=0,f1=0,f2=0,count=0,lru;
//LEAST RECENTLY USED
void print()
{
	int k;
	printf("-----\n");
	for(k=0;k<nof;k++)
		printf("%d\n",frame[k]);
}
int main()
{
	printf("enter no.of pages in reference string \n");
	scanf("%d",&n);
		printf("eneter the pages\n");
	for(i=0;i<n;i++)
		scanf("%d",&ref[i]);
	printf("enter no.of frames:\n");
	scanf("%d",&nof);
	for(j=0;j<nof;j++)
		frame[j]=-1;
	first=0;
	int c[nof];
	
	for(i=0;i<n;i++)
	{
		f1=f2=0;
		for(j=0;j<nof;j++)
		{
			if(frame[j]==ref[i])
			{
				printf("\nPage hit\n");
				page_hit++;
				f1=1;
				break;	
			}
		}
		for(j=0;j<nof;j++)
		{
			if(frame[j]==-1 && f1!=1)
			{
				frame[j]=ref[i];
				f2=1;
				page_fault++;
				count++;
				print();
				break;	
			}
		}
		if(f2!=1 && f1!=1 && count==nof)
		{
			int min=99999;
			k=0;
			//printf("@@@@");
			for(j=0;j<nof;j++)
			{
				for(int rv=i-1;rv>-1;rv--)
				{
					if(frame[j]==ref[rv])
					{
						//c[k++]=rv;
						if(rv<min)
							min=rv;
						break;
					}
				}
			}
			for(int h=0;h<nof;h++)
			{
				if(ref[min]==frame[h])
				{			
					page_fault++;
					frame[h]=ref[i];
					print();
					break;
				}
			}		
		}
	}
	printf("\n\nNo.of pagefaults=%d\n No.of page hits=%d\n",page_fault,page_hit);
}
	
	
	
	
