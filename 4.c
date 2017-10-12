#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int i , j , n , Q[20] , max , head , seek , dist=0;
float avgseek;

void scan();
void cscan();

void main()
{
        int cont,c;
        printf("\nEnter the number of processes in the queue: ");
        scanf("%d" , &n);
        printf("\nEnter the current head position: ");
        scanf("%d" , &head);
        Q[0] = head;
        ++n;
        printf("\nEnter the cylinder number for each request: \n");
        for(i=1 ; i<n ; i++)
        {
                scanf("%d" , &Q[i]);
        }
        printf("\nEnter the maximum number of cylinders: ");
        scanf("%d" , &max);
        do
        {
                printf("\n\nDISK SCHEDULING ALGORITHMS\n\n");
                printf("1. FCFS\n2. SCAN\n3. C-SCAN\n4. Exit\n\nEnter an option: ");
                scanf("%d" , &c);
                seek = 0;
                avgseek = 0;
                switch(c)
                {
                        case 1: for(i=0 ; i<n-1 ; i++)
                                {
                                        dist = abs(Q[i+1] - Q[i]);
                                        seek += dist;
                                }
                                avgseek = seek/n;
                                printf("\nThe total seek time is: %d cylinders\n" , seek);
                                printf("\nThe avg seek time is: %.2f \n" , avgseek);
                                break;
                        case 2: scan();
                                break;
                        case 3: cscan();
                                break;
                        case 4: exit(0);
                                break;
                        default:printf("\nWRONG OPTION!\n");
                }
                printf("\nDO YOU WANT TO CONTINUE? (1 FOR YES): ");
                scanf("%d" , &cont);
        }while(cont == 1);
}

void scan()
{
        int temp , p , Qscan[20] ,  Qtemp[20];

        for(i=0 ; i<n ; ++i)
                Qtemp[i] = Q[i];

        Qtemp[n] = max-1;
        ++n;

        for(i=0 ; i<n-1 ; ++i)
                for(j=0 ; j<n-i-1 ; ++j)
                        if(Qtemp[j] > Qtemp[j+1])
                        {
                                temp = Qtemp[j];
                                Qtemp[j] = Qtemp[j+1];
                                Qtemp[j+1] = temp;
                        }

        for(i=0 ; i<n ; i++)
                if(Qtemp[i] == head)
                {
                        p = i;
                        break;
                }

        int sc=0;
        for(i=p ; i<n ; i++)
        {
                Qscan[sc] = Qtemp[i];
                sc++;
        }

        for(i=p-1 ; i>=0 ; i--)
        {
                Qscan[sc] = Qtemp[i];
                sc++;
        }

        for(i=0 ; i<n ; i++)
                printf("%d\t" , Qscan[i]);

        for(i=0 ; i<n-1 ; i++)
        {
                dist = abs(Qscan[i+1] - Qscan[i]);
                seek += dist;
        }
        avgseek = seek/(n-2);

        printf("\nThe total seek time is: %d cylinders\n" , seek);
        printf("\nThe avg seek time is: %.2f \n" , avgseek);


}

void cscan()
{
        int temp , p , Qcscan[20] ,  Qtemp[20];

        for(i=0 ; i<n ; ++i)
                Qtemp[i] = Q[i];

        Qtemp[n] = max-1;
        ++n;

        Qtemp[n] = 0;
        ++n;

        for(i=0 ; i<n-1 ; ++i)
                for(j=0 ; j<n-i-1 ; ++j)
                        if(Qtemp[j] > Qtemp[j+1])
                        {
                                temp = Qtemp[j];
                                Qtemp[j] = Qtemp[j+1];
                                Qtemp[j+1] = temp;
                        }

        for(i=0 ; i<n ; i++)
                if(Qtemp[i] == head)
                {
                        p = i;
                        break;
                }

        int sc=0;
        for(i=p ; i<n ; i++)
        {
                Qcscan[sc] = Qtemp[i];
                sc++;
        }

        for(i=0 ; i<p ; i++)
        {
                Qcscan[sc] = Qtemp[i];
                sc++;
        }

        for(i=0 ; i<n ; i++)
                printf("%d\t" , Qcscan[i]);

        for(i=0 ; i<n-1 ; i++)
        {
                dist = abs(Qcscan[i+1] - Qcscan[i]);
                seek += dist;
        }
        avgseek = seek/(n-3);

        printf("\nThe total seek time is: %d cylinders\n" , seek);
        printf("\nThe avg seek time is: %.2f \n" , avgseek);


}
