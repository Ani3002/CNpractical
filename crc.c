#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
void main()
{
    int data[100],div[100],codeword[100];
    int dl,divl,tl,i=0,p,pos,pr,e=0;
    char c;
    srand(time(0));
    printf("Enter Dataword   :: ");
    while(c!='\n')
    {
        scanf("%d%c",&data[i],&c);     
        i++;
    }
    dl=i;
    i=0;
    c=' ';
    printf("Enter Divisor   :: ");
    while(c!='\n')
    {
        scanf("%d%c",&div[i],&c);     
        i++;
    }
    
    divl=i;
    tl=dl+divl-1;
    for(i=dl;i<tl;i++) 
    {
        data[i]=0;
    }
    for(i=0;i<tl;i++)
    {
        //printf("%d ",data[i]);
        codeword[i]=data[i];
    }
    //Division
    p=0;
    while(p<tl)
    {
        for(i=0;i<divl;i++)
        {
            data[p+i]=(data[p+i]+div[i])%2;
        }
        while(data[p]==0)
        {
            p++;
        }
        if(tl-p<divl)
        {
            break;
        }
    }
    printf("\n");

    printf("Sending Data ...");

    printf("\n Sending ...\n");
    for(i=0;i<tl;i++)
    {
        codeword[i]=codeword[i]+data[i];
        printf("%d ",codeword[i]);
    }
    printf("\n");
 //Introduce Error
    pr=rand();
    pr=pr%10;
    if(pr<2)
    {
        pos=rand();
        pos=pos%tl;
        codeword[pos]=1-codeword[pos];
    }
    // printf("\nReceived Data :: ");
    
    // for(i=0;i<dl;i++)
    // {
    //     printf("%d ",codeword[i]);
    // }
  //CRC Check
  printf("\n Received ...\n");
    for(i=0;i<tl;i++)
    {
        printf("%d ",codeword[i]);
    }
    printf("\n");
  sleep(2);
  p=0;
  while(p<tl)
  {
        for(i=0;i<divl;i++)
        {
            codeword[p+i]=(codeword[p+i]+div[i])%2;
        }
        while(codeword[p]==0)
        {
            p++;
        }
        if(tl-p<divl)
        {
            break;
        }

  }
  for(i=0;i<tl;i++)
  {
        if(codeword[i]!=0)
        {
            e=1;
            break;
        }
  }
  if(e==1)
  {
      system("color 04");
	  printf("\nError occured, Resend ...");
  }
  else
  {
      system("color 0a");
	  printf("\nNo Error occured, Data Accepted");
  }
}
