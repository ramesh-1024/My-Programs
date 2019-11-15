#include<stdio.h>
int ref[30],frame[10],n,i,j,first,nof,page_hit=0,page_fault=0,f1=0,f2=0,count=0;
//FIRST IN FIRST OUT
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
		printf("enter the pages\n");
	for(i=0;i<n;i++)
		scanf("%d",&ref[i]);
	printf("enter no.of frames:\n");
	scanf("%d",&nof);
	for(j=0;j<nof;j++)
		frame[j]=-1;
	first=0;
	for(i=0;i<n;i++)//REFERENCE STRING
	{
		f1=f2=0;
		for(j=0;j<nof;j++)
		{
			if(frame[j]==ref[i])
			{
				page_hit++;
				printf("Page Hit\n");
				f1=1;
				break;
			}
		}
		for(j=0;j<nof;j++)
		{
			if(frame[j]==-1)
			{
				page_fault++;
				//printf("Page fault, repalcement at--%d--\n",j+1);
				frame[j]=ref[i];
				print();
				count++;
				f2=1;
				break;
			}
		}
		if(f1!=1 && f2!=1 && count==nof)
		{
			frame[first]=ref[i];
			first++;
			print();
			page_fault++;
			//printf("___%d___",first);
			if(first==nof)
				first=0;
		}
	
	}
	printf("no.of page_hits:%d\n",page_hit);
	printf("no.of page_faults:%d\n",page_fault);

}
