#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

int prob(int e)
{
    int r=rand()%100;
    if(r>e)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    FILE *stream,*ackstream;
    int i=1;
    int delay=1;
    int e=30;
    srand(time(0));
    while(i)
    {
        stream=fopen("stream.txt","r");
        fscanf(stream,"%d",&i);
        printf("Received %d\n",i);
        fclose(stream);
        if(prob(e)){
        ackstream=fopen("ackstream.txt","w");
        fprintf(ackstream,"%d",i);
        printf("Acknowledge send %d\n",i);
        fclose(ackstream);
        }
        sleep(delay);
    }
}
