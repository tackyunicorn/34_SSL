#include<stdio.h>
#include<stdlib.h>

void fcfs();
void sjf();
void priority();
void rr();

int i, n, BT[10] , AT[10], PR[10], WT[10], TA[10];
float wt=0, ta=0;

void main()
{
	int cont,c;
	do
	{
		printf("\n\nCPU SCHEDULING ALGORITHMS\n\n");
		printf("1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\n5. Exit\n\nEnter an option: ");
		scanf("%d" , &c);
		switch(c)
		{
			case 1: fcfs();
				break;
			case 2: sjf();
				break;
			case 3: priority();
				break;
			case 4: rr();
				break;
			case 5: exit(0);
				break;
			default:printf("\nWRONG OPTION!\n");
		}
		printf("\nDO YOU WANT TO CONTINUE? (1 FOR YES): ");
		scanf("%d" , &cont);
	}while(cont == 1);
}

void fcfs()
{
	printf("\nEnter the number of processes: ");
	scanf("%d" , &n);
	printf("\nEnter the Burst times (Arrival time is taken to be zero for all processes): \n");
	for(i=1 ; i<=n ; i++)
	{
		printf("BT[%d] = " , i);
		scanf("%d" , &BT[i]);
	}

	WT[1] = 0;
	for(i=1 ; i<n ; i++)
	{
		WT[i+1] = WT[i] + BT[i];
		wt += WT[i+1];
	}

	TA[1] = BT[1];
	ta = BT[1];
	for(i=1 ; i<n ; i++)
	{
		TA[i+1] = TA[i] + BT[i+1];
		ta += TA[i+1];
	}

	wt /= n;
	ta /= n;

	printf ("\nThe waiting and turnaround times of all processes are: \n");
	printf("WT\tTA\n");
	for(i=1 ; i<=n ; i++)
	{
		printf("%d\t%d\n" , WT[i] , TA[i]);
	}
	printf("\nThe avg. waiting time is: %f\n" , wt);
	printf("\nThe avg. turnaround time is: %f\n" , ta);
}

void sjf()
{
	printf("\nEnter the number of processes: ");
        scanf("%d" , &n);
        printf("\nEnter the Burst times: \n");
        for(i=1 ; i<=n ; i++)
        {
                printf("BT[%d] = " , i);
                scanf("%d" , &BT[i]);
        }


	printf ("\nThe waiting and turnaround times of all processes are: \n");
        printf("WT\tTA\n");
        for(i=1 ; i<=n ; i++)
        {
                printf("%d\t%d\n" , WT[i] , TA[i]);
        }
        printf("\nThe avg. waiting time is: %f\n" , wt);
        printf("\nThe avg. turnaround time is: %f\n" , ta);
}

void priority()
{
}

void rr()
{
}
