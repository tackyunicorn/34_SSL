#include<stdio.h>
#include<stdlib.h>

void fcfs();
void sjf();
void priority();
void rr();

int i, j, n, BT[10] , AT[10], PR[10], WT[10], TA[10];
float wt, ta;

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

	wt=0;
	ta=0;

	WT[1] = 0;
	for(i=1 ; i<n ; i++)
	{
		WT[i+1] = WT[i] + BT[i];
		wt += WT[i+1];
	}

	for(i=1 ; i<=n ; i++)
	{
		TA[i] = BT[i] + WT[i];
		ta += TA[i];
	}

	wt /= n;
	ta /= n;

	printf ("\nThe waiting and turnaround times of all processes are: \n");
	printf("PNO:\tBT\tWT\tTA\n");
	for(i=1 ; i<=n ; i++)
	{
		printf("P%d\t%d\t%d\t%d\n" , i , BT[i] , WT[i] , TA[i]);
	}
	printf("\nThe avg. waiting time is: %f\n" , wt);
	printf("\nThe avg. turnaround time is: %f\n" , ta);
}

void sjf()
{
	int BT_order[10], temp;
	printf("\nEnter the number of processes: ");
        scanf("%d" , &n);
        printf("\nEnter the Burst times(Arrival time is taken to be zero for all processes): \n");
        for(i=1 ; i<=n ; i++)
        {
                printf("BT[%d] = " , i);
                scanf("%d" , &BT[i]);
		BT_order[i] = BT[i];
        }

	for(i=1 ; i<n ; i++)
	{
		for(j=1 ; j<n ; j++)
		{
			if(BT_order[j] > BT_order[j+1])
			{
				temp = BT_order[j];
				BT_order[j] = BT_order[j+1];
				BT_order[j+1] = temp;
			}
		}
	}

	wt=0;
	ta=0;

	WT[1] = 0;
        for(i=1 ; i<n ; i++)
        {
                WT[i+1] = WT[i] + BT_order[i];
                wt += WT[i+1];
        }

        for(i=1 ; i<=n ; i++)
        {
                TA[i] = BT_order[i] + WT[i];
                ta += TA[i];
        }

        wt /= n;
        ta /= n;

	printf ("\nThe waiting and turnaround times of all processes are: \n");
        printf("PNO:\tBT\tWT\tTA\n");
        for(i=1 ; i<=n ; i++)
	{
		for(j=1 ; j<=n ; j++)
		{
			if(BT[i] == BT_order[j])
			{
                		printf("P%d\t%d\t%d\t%d\n" , i , BT[i] , WT[j] , TA[j]);
			}
		}
	}
        printf("\nThe avg. waiting time is: %f\n" , wt);
        printf("\nThe avg. turnaround time is: %f\n" , ta);
}

void priority()
{
	int PR_order[10], BT_order[10], temp;
        printf("\nEnter the number of processes: ");
        scanf("%d" , &n);
        printf("\nEnter the Burst times(Arrival time is taken to be zero for all processes): \n");
        for(i=1 ; i<=n ; i++)
        {
                printf("BT[%d] = " , i);
                scanf("%d" , &BT[i]);
        }
	printf("\nEnter the Priorities: \n");
        for(i=1 ; i<=n ; i++)
        {
                printf("PR[%d] = " , i);
                scanf("%d" , &PR[i]);
		PR_order[i] = PR[i];
        }

        for(i=1 ; i<n ; i++)
        {
                for(j=1 ; j<n ; j++)
                {
                        if(PR_order[j] > PR_order[j+1])
                        {
                                temp = PR_order[j];
                                PR_order[j] = PR_order[j+1];
                                PR_order[j+1] = temp;
                        }
                }
        }

	for(i=1 ; i<=n ; i++)
	{
		for(j=1 ; j<=n ; j++)
		{
			if(PR_order[i] == PR[j])
			{
				BT_order[i] = BT[j];
			}
		}
	}


	wt=0;
        ta=0;

        WT[1] = 0;
        for(i=1 ; i<n ; i++)
        {
                WT[i+1] = WT[i] + BT_order[i];
                wt += WT[i+1];
        }

        for(i=1 ; i<=n ; i++)
        {
                TA[i] = BT_order[i] + WT[i];
                ta += TA[i];
        }

        wt /= n;
        ta /= n;

        printf ("\nThe waiting and turnaround times of all processes are: \n");
        printf("PNO:\tBT\tPR\tWT\tTA\n");
        for(i=1 ; i<=n ; i++)
        {
                for(j=1 ; j<=n ; j++)
                {
                        if(PR[i] == PR_order[j])
                        {
                                printf("P%d\t%d\t%d\t%d\t%d\n" , i , BT[i] , PR[i] , WT[j] , TA[j]);
                        }
                }
        }
	printf("\nThe avg. waiting time is: %f\n" , wt);
        printf("\nThe avg. turnaround time is: %f\n" , ta);
}

void rr()
{
}
