#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *stream;
    int i=1;
    int delay=2;
    while(i)
    {
        sleep(delay);
        stream=fopen("stream.txt","r");
        fscanf(stream,"%d",&i);
        printf("Received %d\n",i);
        fclose(stream);
    }
}
