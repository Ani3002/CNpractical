#include<stdio.h>
#include<time.h>
#include<unistd.h>
void main()
{
    int pno=0,pack=-1;
    FILE *in,*out;
    while(1)
    {
        
        printf("\nSENDING %d\n",pno);
        in=fopen("instream.txt","w");
        fprintf(in,"%d",pno);
        fclose(in);
        out=fopen("outstream.txt","r");
        fscanf(out,"%d",&pack);
        fclose(out);
        printf("Waiting");
        while(pno!=pack){
            // printf("waiting...");
            sleep(1);
            out=fopen("outstream.txt","r");
            fscanf(out,"%d",&pack);
            fclose(out);
            // printf("\b\b\b\b\b\b\b\b\b\b");
            printf(".");
        }
        printf("\nAcknowledgment received %d",pno);
        pno++;
        
        
    }
}