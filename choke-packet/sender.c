#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
 void main()
 {
    FILE *stream,*cinstream;
    int i=1,cp;
    int delay=1,f=1;
    while(i)
    {
        if(f)
        {
        cinstream=fopen("r1-s.txt","r");
        fscanf(cinstream,"%d",&cp);
        fclose(cinstream);
        if(cp==-1)
        {
            printf("Choke packet received ...\n");
            delay=2;
            f=0;
        }
        }
        stream=fopen("s-r1.txt","w");
        fprintf(stream,"%d",i);
        printf("Sending %d\n",i);
        i++;
        fclose(stream);
        sleep(delay);
    }
    
 }