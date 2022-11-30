#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *instream,*cstream;
    int i=1;
    int delay=2,f=1;
    int timer=0;
    while(i)
    {
        instream=fopen("r3-r.txt","r");
        fscanf(instream,"%d",&i);
        printf("Received %d\n",i);
        fclose(instream);
        sleep(delay);
        timer++;
        if(timer>5 && f)
        {
            f=0;
            cstream=fopen("r-r3.txt","w");
            fprintf(cstream,"%d",-1);
            printf("Choke Packet Sent ...\n");
            fclose(cstream);
        }
    }
}
