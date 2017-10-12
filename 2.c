#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define clear() printf("\033[H\033[J")

char fname[100][10] , temp[10];
int dir[100] , type[100] , ptr=1 , fcnt , dcnt=0;

void sld();
void tld();
void hldsc();
void hld();
void inorder(int);
void display();
void del();
void dcreate(int);
void create();
int traverse(char []);

void main()
{
        clear();
        int cont,c;
        do
        {
                printf("\n\nFILE ORGANIZATION TECHNIQUES\n\n");
                printf("1. Single Level Directory\n2. Two Level Directory\n3. Hierarchical Level Directory\n4. Exit\n\nEnter an option: ");
                scanf("%d" , &c);
                switch(c)
                {
                        case 1: sld();
                                break;
                        case 2: tld();
                                break;
                        case 3: hld();
                                break;
                        case 4: exit(0);
                                break;
                        default:printf("\nWRONG OPTION!\n");
                }
                printf("\nDO YOU WANT TO CONTINUE? (1 FOR YES): ");
                scanf("%d" , &cont);
        }while(cont == 1);
}

void sld()
{
        clear();
        struct
        {
                char dname[10] , fname[10][10];
                int fct;
        }dir;
        int i , flag , ch , cont;
        char file[10];
        dir.fct = 0;

        printf("\nEnter the name of the directory: ");
        scanf("%s" , dir.dname);

        do
        {
                printf("\n\nSINGLE LEVEL DIRECTORY\n\n");
                printf("1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Main Menu\n\nEnter an option: ");
                scanf("%d" , &ch);
                switch(ch)
                {
                        case 1: printf("\nEnter the name of the file to be created: ");
                                scanf("%s" , file);
                                flag = 0;
                                for(i=0 ; i<dir.fct ; i++)
                                {
                                        if(strcmp(file , dir.fname[i]) == 0)
                                        {
                                                flag = 1;
                                                break;
                                        }
                                }
                                if(flag == 1)
                                {
                                        printf("\nFile of the same name already exists!\nAborting File Creation...\n");
                                }
                                else
                                {
                                        printf("\nFile Created!\n");
                                        strcpy(dir.fname[dir.fct] , file);
                                        ++dir.fct;
                                }
                                break;
                        case 2: printf("\nEnter the name of the file to be deleted: ");
                                scanf("%s" , file);
                                flag = 0;
                                for(i=0 ; i<dir.fct ; i++)
                                {
                                        if(strcmp(file , dir.fname[i]) == 0)
                                        {
                                                flag = 1;
                                                break;
                                        }
                                }
                                if(flag == 1)
                                {
                                        printf("\nThe file was deleted successfully!\n");
                                        strcpy(dir.fname[i] , dir.fname[dir.fct-1]);
                                        --dir.fct;
                                }
                                else
                                        printf("\nThe file was not found!\n");
                                break;
                        case 3: printf("\nEnter the name of the file to be searched: ");
                                scanf("%s" , file);
                                flag = 0;
                                for(i=0 ; i<dir.fct ; i++)
                                {
                                        if(strcmp(file , dir.fname[i]) == 0)
                                        {
                                                flag = 1;
                                                break;
                                        }
                                }
                                if(flag == 1)
                                {
                                        printf("\nThe file \"%s\" was found successfully!\n" , dir.fname[i]);
                                }
                                else
                                        printf("\nThe file was not found!\n");

                                break;
                        case 4: printf("\nDIRECTORY: %s\n" , dir.dname);
                                if(dir.fct == 0)
                                        printf("\nThe directory is empty!\n");
                                else
                                {
                                        printf("\nThe files are: \n");
                                        for(i=0 ; i<dir.fct ; i++)
                                        {
                                                printf("%s\n" , dir.fname[i]);
                                        }
                                }
                                break;
                        case 5: main();
                                break;
                        default:printf("\nWRONG OPTION!\n");
                }
                printf("\nDO YOU WANT TO CONTINUE? (1 FOR YES): ");
                scanf("%d" , &cont);
        }while(cont == 1);
}

void tld()
{
        clear();
        struct
        {
                char dname[10] , fname[10][10];
                int fct;
        }dir[10];
        int dct=0 , i , j , flag , flag1 , flag2 , ch , cont;
        char file[10] , dirname[10];

	for(i=0 ; i<10 ; i++)
	{
		dir[i].fct = 0;
	}

        do
        {
                printf("\n\nTWO LEVEL DIRECTORY\n\n");
                printf("1. Create Directory\n2. Create File\n3. Delete File\n4. Search File\n5. Display Files\n6. Main Menu\n\nEnter an option: ");
                scanf("%d" , &ch);
                switch(ch)
                {
                        case 1: printf("\nEnter the name of the directory: ");
                                scanf("%s" , dirname);
                                flag = 0;
                                for(i=0 ; i<dct ; i++)
                                {
                                        if(strcmp(dirname , dir[i].dname) == 0)
                                        {
                                                flag = 1;
                                                break;
                                        }
                                }
                                if(flag == 1)
                                {
                                        printf("\nDirectory of the same name already exists!\nAborting Directory Creation...\n");
                                }
                                else
                                {
                                        printf("\nDirectory Created!\n");
                                        strcpy(dir[i].dname , dirname);
                                        ++dct;
                                }
                                break;
                        case 2: printf("\nEnter the name of the directory: ");
                                scanf("%s" , dirname);
                                flag1 = 0;
                                for(i=0 ; i<dct ; i++)
                                {
                                        if(strcmp(dirname , dir[i].dname) == 0)
                                        {
                                                flag1 = 1;
                                                break;
                                        }
                                }
                                if(flag1 == 1)
                                {
                                        flag2 = 0;
                                        printf("\nEnter the name of the file to be created: ");
                                        scanf("%s" , file);
                                        for(j=0 ; j<dir[i].fct ; j++)
                                        {
                                                if(strcmp(file , dir[i].fname[j]) == 0)
                                                {
                                                        flag2 = 1;
                                                        break;
                                                }
                                        }
                                        if(flag2 == 1)
                                        {
                                                printf("\nFile of the same name already exists!\nAborting File Creation...\n");
                                        }
                                        else
                                        {
                                                printf("\nFile Created!\n");
                                                strcpy(dir[i].fname[dir[i].fct] , file);
                                                ++dir[i].fct;
                                        }

                                }
                                else
                                {
                                        printf("\nDirectory does not exist!!\n");
                                }
                                break;
                        case 3: printf("\nEnter the name of the directory: ");
                                scanf("%s" , dirname);
                                flag1 = 0;
                                for(i=0 ; i<dct ; i++)
                                {
                                        if(strcmp(dirname , dir[i].dname) == 0)
                                        {
                                                flag1 = 1;
                                                break;
                                        }
                                }
                                if(flag1 == 1)
                                {
                                        flag2 = 0;
                                        printf("\nEnter the name of the file to be deleted: ");
                                        scanf("%s" , file);
                                        for(j=0 ; j<dir[i].fct ; j++)
                                        {
                                                if(strcmp(file , dir[i].fname[j]) == 0)
                                                {
                                                        flag2 = 1;
                                                        break;
                                                }
                                        }
                                        if(flag2 == 1)
                                        {
						dir[i].fct--;
						strcpy(dir[i].fname[j] , dir[i].fname[dir[i].fct]);
                                                printf("\nFile successfully deleted!\n");
                                        }
                                        else
                                        {
                                                printf("\nFile not found!\n");
                                        }

                                }
                                else
                                {
                                        printf("\nDirectory does not exist!!\n");
                                }
                                break;
                        case 4: printf("\nEnter the name of the directory: ");
                                scanf("%s" , dirname);
                                flag1 = 0;
                                for(i=0 ; i<dct ; i++)
                                {
                                        if(strcmp(dirname , dir[i].dname) == 0)
                                        {
                                                flag1 = 1;
                                                break;
                                        }
                                }
                                if(flag1 == 1)
                                {
                                        flag2 = 0;
                                        printf("\nEnter the name of the file to be searched: ");
                                        scanf("%s" , file);
                                        for(j=0 ; j<dir[i].fct ; j++)
                                        {
                                                if(strcmp(file , dir[i].fname[j]) == 0)
                                                {
                                                        flag2 = 1;
                                                        break;
                                                }
                                        }
                                        if(flag2 == 1)
                                        {
                                                printf("\nFile \"%s\" was found successfully!\n" , file);
                                        }
                                        else
                                        {
                                                printf("\nFile not found!\n");
                                        }

                                }
                                else
                                {
                                        printf("\nDirectory does not exist!!\n");
                                }
                                break;
                        case 5: for(i=0 ; i<dct ; i++)
				{
					printf("\nDIRECTORY: %s\n" , dir[i].dname);
                                	if(dir[i].fct == 0)
                                        	printf("\nThe directory is empty!\n");
                                	else
                                	{
                                        	printf("\nThe files are: \n");
                                        	for(j=0 ; j<dir[i].fct ; j++)
                                        	{
                                                	printf("%s\n" , dir[i].fname[j]);
                                        	}
                                	}
				}
                                break;
                        case 6: main();
                                break;
                        default:printf("\nWRONG OPTION!\n");
                }
                printf("\nDO YOU WANT TO CONTINUE? (1 FOR YES): ");
                scanf("%d" , &cont);
        }while(cont == 1);
}

void hldsc()
{
	clear();
        int cont,c,i;
	system("mkdir ~/ROOT");
	char dname[30] , fname[30] , mkcmd[30] , rmcmd[30] , touchcmd[30] , cdcmd[30] , path[30]="~/ROOT/";
        do
        {
                printf("\n\nHIERARCHICAL FILE ORGANIZATION\n");
		printf("CURRENT PATH: %s\n\n" , path);
                printf("1. Create Directory\n2. Delete Directory\n3. Create File\n4. Delete File\n5. Change Directory\n6. Go back up a directory\n");
                printf("7. List contents from ROOT\n8. Main Menu\n\nEnter an option: ");
                scanf("%d" , &c);
                switch(c)
                {
                        case 1: printf("\nEnter the directory name: ");
				scanf("%s" , dname);
				sprintf(mkcmd ,"mkdir %s/%s", path , dname);
				system(mkcmd);
                                break;
                        case 2: printf("\nEnter the directory to be deleted: ");
				scanf("%s" , dname);
				sprintf(rmcmd ,"rm -R %s/%s", path , dname);
				system(rmcmd);
                                break;
                        case 3: printf("\nEnter the file to be created: ");
				scanf("%s" , fname);
				sprintf(touchcmd ,"touch %s/%s", path , fname);
				system(touchcmd);
                                break;
                        case 4: printf("\nEnter the file to be deleted: ");
				scanf("%s" , fname);
				sprintf(rmcmd ,"rm %s/%s", path , fname);
				system(rmcmd);
                                break;
                        case 5: printf("\nEnter the directory to move to: ");
				scanf("%s" , dname);
				sprintf(cdcmd ,"cd %s/%s", path , dname);
				int a = system(cdcmd);
				if(a == 512)
				printf("\nIncorrect name!\n");
				else
				{
					strcat(path , dname);
					strcat(path , "/");
				}
                                break;
                        case 6: printf("\nMoved to parent directory!\n");
				if(strcmp(path , "~/ROOT/") != 0)
				{
					for(i=strlen(path)-2 ; i>=6 ; i--)
        				{
                				if(path[i] == '/')
                        			break;
        				}
					path[i+1] = '\0';
				}
                                break;
                        case 7: system("ls -R ~/ROOT");
                                break;
                        case 8: main();
                                break;
                        default:printf("\nWRONG OPTION!\n");
                }
                printf("\nDO YOU WANT TO CONTINUE? (1 FOR YES): ");
                scanf("%d" , &cont);
        }while(cont == 1);
}

void hld()
{
	clear();
        int cont , c;
        do
        {
                printf("\n\nHIERARCHICAL FILE ORGANIZATION\n\n");
                printf("1. Create File/Directory\n2. Delete File/Directory\n3. Display Files\n4. Main Menu\n\nEnter an option: ");
                scanf("%d",&c);
                switch(c)
                {
                        case 1: create();
                                break;
                        case 2: del();
                                break;
                        case 3: display();
                                break;
                        case 4: main();
                                break;
                        default:printf("\nWRONG OPTION!\n");
                }
                printf("\nDO YOU WANT TO CONTINUE? (1 FOR YES): ");
                scanf("%d" , &cont);
        }while(cont==1);
}

void inorder(int tempptr)
{
        if(type[tempptr]==1 || type[tempptr]==2)
        {
                inorder(2*tempptr);
                printf("%s\t",fname[tempptr]);
                inorder(2*tempptr+1);
        }
}

void display()
{
        int tempptr=1;
        inorder(tempptr);
        printf("\n");
}

int traverse(char temp[10])
{
        int i;
        for(i=1 ; i<100 ; i++)
        {
                if(strcmp(temp,fname[i]) == 0)
                {
                        ptr=i;
                        return ptr;
                }
        }
        return 0;
}

void del()
{
        printf("\nEnter the name of the file/dir to be deleted: ");
        scanf("%s" , temp);
        ptr=traverse(temp);
        if(ptr == 0)
        {
                printf("\nThe file/dir was not found!\n");
        }
        else
        {
                type[ptr]=0;
                memset(fname[ptr], 0, 10);
        }
}

void dcreate(int o)
{
        if(o == 1)
        {
                printf("\nEnter the file name: ");
                scanf("%s" , fname[ptr]);
                type[ptr]=1;
                fcnt++;
        }
        else
        {
                printf("\nEnter the directory name: ");
                scanf("%s" , fname[ptr]);
                type[ptr]=2;
                dcnt++;
        }

}

void create()
{
        int o;
        printf("\nEnter the type to create\n1. File\n2. Directory\n\nEnter an option: ");
        scanf("%d" , &o);
        if(dcnt==0)
        {
                printf("\nEnter the root directory name: ");
                scanf("%s" , fname[1]);
                type[1] = 2;
                dcnt++;
        }
        else
        {
                printf("\nEnter the parent directory name: ");
                scanf("%s" , temp);
                ptr = traverse(temp);
                if(ptr == 0)
                {
                        printf("\nThe directory was not found!\n");
                }
                else if(type[ptr] != 2)
                {
                        printf("\nNot a directory!\n");
                }
                else if(type[2*ptr] < 1)
                {
                        ptr = 2*ptr;
                        dcreate(o);
                }
                else if(type[2*ptr+1] < 1)
                {
                        ptr = 2*ptr+1;
                        dcreate(o);
                }
		 else
                {
                        printf("\nRequested directory is full!\n");
                }
        }
}
