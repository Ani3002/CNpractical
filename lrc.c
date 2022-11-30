#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int data[16],grid[5][5];
int dwl;
void read_data()
{
    int i=0;
    char c=' ';
    printf("Enter the data -> ");
    while(c!='\n')
    {
        scanf("%d%c",&data[i],&c);
        i++;
    }
    dwl=i;
}
void generator()
{
    int p,i,k=0,j,s;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            grid[i][j]=data[k];
            k++;
        }
    }
    for(i=0;i<4;i++)
    {
        s=0;
        for(j=0;j<3;j++)
        {
            s=s+grid[j][i];
        }
        grid[j][i]=s%2;
    }
    printf("Sending ...\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}
void checker()
{
    int i,s,k=0,j,f=0;
    int rd;
    for(i=0;i<4;i++)
    {
        s=0;
        for(j=0;j<3;j++)
        {
            s=s+grid[j][i];
        }
        rd=s%2;
        if(grid[j][i]!=rd)
        {
            f=1;
        }
    }
    if(f==0)
    {
        printf("Data Accepted \n");
        // for(i=0;i<12;i++)
        // {
        //     printf("%d ",data[i]);
        // }
        for(i=0;i<3;i++)
        {
            for(j=0;j<4;j++)
            {
                printf("%d ",grid[i][j]);
            }
        }
    }
    else
    {
        printf("Error !!! Please Resend");
    }
}
void transmission(int error)
{
    int eprob,eposx,eposy;
    srand(time(0));
    eprob=(rand()%100)+1;
    if(eprob<=error)
    {
        eposx=rand()%4;
        eposy=rand()%4;
        grid[eposx][eposy]=1-grid[eposx][eposy];
    }
}
 void main()
 {
    read_data();
    generator();
    transmission(50);
    checker();
    // print_array();

 }