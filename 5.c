#include<stdio.h>
#include<stdlib.h>

int i , j , k , ns , seq[30] , nf , p[30] , pfcnt;

void enter();
void fifo();
void lru();
void lfu();
void init();
int hit(int data);
int hitindex(int data);

void main()
{
        int c , cont;
        do
        {
                printf("\nPAGE REPLACEMENT ALGORITHMS\n");
                printf("\n1. Enter the data\n2. FIFO\n3. LRU\n4. LFU\n5. Exit\n");
                printf("\nEnter your option: ");
                scanf("%d" , &c);
                printf("\n");
                switch(c)
                {
                        case 1: enter();
                                break;
                        case 2: fifo();
                                break;
                        case 3: lru();
                                break;
                        case 4: lfu();
                                break;
                        case 5: exit(0);
                                break;
                }
                printf("\nDO YOU WANT TO CONTINUE? (1 FOR YES): ");
                scanf("%d" , &cont);
        }while(cont == 1);
}

void enter()
{
        printf("\nEnter the length of the page reference sequence: ");
        scanf("%d" , &ns);
        printf("\nEnter the sequence of the pages: ");
        for(i=0 ; i<ns ; ++i)
                scanf("%d" , &seq[i]);
        printf("Enter the number of frames: ");
        scanf("%d" , &nf);
}

void init()
{
        pfcnt=0;
        for(i=0 ; i<nf ; ++i)
                p[i]=9999;
}

int hit(int data)
{
        int hit=0;
        for(j=0 ; j<nf ; ++j)
        {
                if(p[j] == data)
                {
                        hit = 1;
                        break;
                }
        }
        return hit;
}

int hitindex(int data)
{
        int hitind;
        for(j=0 ; j<nf ; ++j)
        {
                if(p[j] == data)
                {
                        hitind = j;
                        break;
                }
        }
        return hitind;
}

void fifo()
{
        init();
        for(i=0 ; i<ns ; ++i)
        {
                printf("For [%d]: " , seq[i]);

                if(hit(seq[i]) == 0)
                {
                        for(k=0 ; k<nf-1 ; ++k)
                                p[k] = p[k+1];

                        p[k] = seq[i];
                        pfcnt++;

                        for(k=0 ; k<nf ; ++k)
                        {
                                if(p[k] != 9999)
                                        printf(" %d" , p[k]);
                        }

                        printf("\n");
                }
                else
                        printf(" No page fault!\n");
        }
        printf("\n\nThe total number of page faults is: %d\n\n" , pfcnt);
}

void lru()
{
        init();
	int least[50];
	for(i=0 ; i<ns ; i++)
	{
		printf("For [%d]: ", seq[i]);
		if(hit(seq[i]) == 0)
		{
			for(j=0 ; j<nf ; j++)
			{
				int pg=p[j];
				int found=0;
				for(k=i-1 ; k>=0 ; k--)
				{
					if(pg == seq[k])
					{
						least[j]=k;
						found=1;
						break;
					}
					else
						found=0;
				}
				if(!found)
					least[j]=-9999;
            		}

			int min=9999;
			int repindex;
			for(j=0; j<nf ; j++)
			{
				if(least[j]<min)
				{
					min=least[j];
					repindex=j;
				}
			}
			p[repindex]=seq[i];
			pfcnt++;

			for(k=0 ; k<nf ; ++k)
                        {
                                if(p[k] != 9999)
                                        printf(" %d" , p[k]);
                        }

                        printf("\n");

		}
		else
			printf(" No page fault!\n");
	}
	printf("\n\nThe total number of page faults is: %d\n\n" , pfcnt);
}

void lfu()
{
        init();
}
