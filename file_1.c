#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<time.h> 
#include<conio.h>
#define Marrival_timeX 32767  


void delay(double number_of_seconds) 
{
    double milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
}

struct process
{
	int arrival_time;       // arrival time
	int burst_time;         // burst time 
	int pid;                // process id
	int queue;              // queue it belongs
	int completion_time;    // completion time
	int w;
	int t;
	int temp_b;
};


void printScenario(struct process p[],int len)
{
	printf("\n\n--------------------------------------------------------------------------------------------------------------------------- \n");
	printf("    |  Process    |    Arrival Time    |   Burst Time  |      Completion Time     |     Waiting Time     |   Turn-Around Time \n");
	printf("    -------------------------------------------------------------------------------------------------------------------------- \n");
	for(int i=0;i<len;i++)
	{
		printf("        P%d                 %d                   %d               %d                       %d                      %d\n",p[i].pid,p[i].arrival_time,p[i].temp_b,p[i].completion_time,p[i].w,p[i].t);
	}
} 

/*
void sort(struct process *p,int n)
{
	// array of p
	// Sort p
	for(int i=1;i<n;i++)
	{
		struct process temp=p[i];
		int index=0;
		for(int j=i-1;j>=0;j--)
		{
			if(p[j].arrival_time>temp.arrival_time)
			{
				p[j+1]=p[j];
			}
			else if(p[j].arrival_time==temp.arrival_time)  // same arrival time.
			{
				if(p[j].queue<temp.queue)
				{
					index=j+1;
					break;
				}
				else if(p[j].queue==temp.queue) // same arrival time and same query.
				{
					if(p[j].queue==1) // belongs to the first queue
					{
						if(p[j].burst_time<=temp.burst_time)
						{
							index=j+1;
							break;
						}
						else
						{
							p[j+1]=p[j];
						}
					}
					else    // belongs to the second queue 
					{
						index=j+1;
						break;
					}
				}
				else
				{
					p[j+1]=p[j];
				}
			}
			else
			{
				index=j+1;
				break;
			}
		}
		p[index]=temp;
	}
}
*/

void printQueue(int a[],int n)
{
	printf(" Queue 2 : \n");
	for(int i=0;i<n;i++)
	printf(" %d",a[i]);
	printf("\n");
}

