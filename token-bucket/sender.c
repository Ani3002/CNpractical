#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 void main()
 {
    FILE *stream;
    int i=1;
    int delay=1;
    int tokens=3;//Number of initial tokens
    int timer=0;
    while(i)
    {
        if(tokens>0){
        stream=fopen("stream.txt","w");
        fprintf(stream,"%d",i);//only send if tokens are in the bucket
        tokens--;//remove a token and then send a packet
        printf("Sending %d\n",i);
        fclose(stream);
        i++;
        }
        else
        {
        stream=fopen("stream.txt","w");
        fprintf(stream,"%d",-1);//if there are no tokens left write -1 indicating no transmission
        printf("No tokens available ...\n");
        fclose(stream);   
        }
        timer++;
        if(timer==5)
        {
            timer=0;
            tokens++;//after every five seconds add one token to the bucket
        }
        
        sleep(delay);
    }
    
 }