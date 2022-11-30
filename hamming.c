#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int data[4],code[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int dwl=4,cwl=7;
void print_array()
{
int i;
printf("\n");
for(i=1;i<=cwl;i++)
{
printf("%d ",code[i]);
}
printf("\n");
}
void read_data()
{
int i=0,j,k;
char c=' ';
printf("Enter the data -> ");
for(i=0;i<dwl;i++)
{
scanf("%d",&data[i]);
}
i=0;
k=0;
for(j=1;j<=cwl;j++)
{
if(pow(2,i)==j)
{
i++;
continue;
}
code[j]=data[k];
k++;
}
}
void generator()
{
code[1]=(code[3]+code[5]+code[7])%2;
code[2]=(code[3]+code[6]+code[7])%2;
code[4]=(code[5]+code[6]+code[7])%2;
}void checker()
{
int e0,e1,e2,epos,i,j,k;
e0=(code[1]+code[3]+code[5]+code[7])%2;
e1=(code[2]+code[3]+code[6]+code[7])%2;
e2=(code[4]+code[5]+code[6]+code[7])%2;
epos=e2*4+e1*2+e0;
if(epos)
{
printf("Error at bit %d!!! \nCorrected Message \n",epos);
code[epos]=1-code[epos];
print_array();
}
else{
printf("No Error !!!");
}
i=0;
printf("\n\nMessage Acctepted :: ");
for(j=1;j<=cwl;j++)
{
if(pow(2,i)==j)
{
i++;
continue;
}
printf("%d ",code[j]);
}
}
void transmission(int error)
{
int eprob,epos;
srand(time(0));
eprob=(rand()%100)+1;
if(eprob<=error)
{
epos=(rand()%cwl)+1;
code[epos]=1-code[epos];
}
}
void main()
{
read_data();
generator();
printf("Sending hamming code ...");
print_array();
transmission(10);
printf("Received Hamming Code ... ");
print_array();checker();
printf("\n\n\n\n\n\n");
system("pause");
}