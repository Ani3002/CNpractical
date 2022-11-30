#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *stream;
    int i=1;
    int delay=1;
    while(i)
    {
        stream=fopen("stream.txt","r");
        fscanf(stream,"%d",&i);
        if(i==-1)
        {
            printf("\nNo transmission ...");
        }
        else
        {
            printf("\nReceived %d\n",i);
        }
        fclose(stream);
        sleep(delay);
    }
}
