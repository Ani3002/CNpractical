#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int pno=0;
    int prob,error;
    FILE *in,*out;

    srand(time(0));
    error=70;
    while(1)
    {
        in=fopen("instream.txt","r");
        out=fopen("outstream.txt","w");
        fscanf(in,"%d",&pno);
        printf("\nReceived %d",pno);
        do{
        prob=rand()%100;
        sleep(5);
        }
        while(prob>error);
        fprintf(out,"%d",pno);
        printf("\nAcknowledged %d",pno);
        fclose(in);
        fclose(out);
        sleep(2);
    }
}