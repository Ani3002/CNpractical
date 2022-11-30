#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 void main()
 {
    FILE *stream;
    int i=1,j=0,k=0;
    int delay=1;
    int bucket[1024];
    while(i)
    {
        sleep(delay);
        //put on the bucket
        bucket[j]=i;
        j++;//points to the end of bucket
        sleep(delay);
        stream=fopen("stream.txt","w");
        //send from bucket
        fprintf(stream,"%d",bucket[k]);
        printf("Sending %d\n",bucket[k]);
        k++;//points to the number to be send from the bucket
        fclose(stream);
        i++;
    }
    
 }