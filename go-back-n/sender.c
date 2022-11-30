#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

 void main()
 {
    FILE *stream,*ackstream;
    int i=1;
    int delay=1;
    int ack;
    int f=1,end=0,beg=0,ackframe=1;
    int ackbuffer[1024];
    int window=5,wsize;
    int k;
    wsize=window;
    while(i)
    {
        stream=fopen("stream.txt","w");
        fprintf(stream,"%d",i);
        printf("\nSending %d",i);
        fclose(stream);
        sleep(delay);
        ackstream=fopen("ackstream.txt","r");
        fscanf(ackstream,"%d",&ack);
        fclose(ackstream);
        if(end==0 || ackbuffer[end-1]!=ack)
        {
            ackbuffer[end]=ack;
            end++;
        }
        i++;
        window--;
        if(window==0)
        {
            window+=3;
            if(ackbuffer[beg]!=ackframe)
            {
                beg=end;
                i=ackframe;
            }
            else
            {
                printf("\nAcknowledged frame %d",ackframe);
                ackframe++;
                beg++;
            }
        }
    }
    printf("\n\n");
    for(k=0;k<30;k++)
    {
        printf("%d-",ackbuffer[k]);
    }
    
 }