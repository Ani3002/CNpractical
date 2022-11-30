#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 void main()
 {
    FILE *instream,*outstream,*cinstream,*coutstream;
    int i=1,cp;
    int delay=1,f=1;
    while(i)
    {
        if(f){
            cinstream=fopen("r2-r1.txt","r");
            fscanf(cinstream,"%d",&cp);
            fclose(cinstream);
            if(cp==-1)
            {
                coutstream=fopen("r1-s.txt","w");
                fprintf(coutstream,"%d",-1);
                printf("Choke Packet Forwarded ...\n");
                delay=2;
                fclose(coutstream);
                f=0; 
            }
        }
        instream=fopen("s-r1.txt","r");
        outstream=fopen("r1-r2.txt","w");
        fscanf(instream,"%d",&i);
        fprintf(outstream,"%d",i);
        printf("Forwarding %d\n",i);
        fclose(instream);
        fclose(outstream);
        sleep(delay);
    }
    
 }