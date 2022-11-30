#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int data[100];
int dwl;
void print_array() {
  int i;
  printf("\n");
  for (i = 0; i < dwl; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}
void read_data() {
  int i = 0;
  char c = ' ';
  printf("Enter the data -> ");
  while (c != '\n') {
    scanf("%d%c", &data[i], &c);
    i++;
  }
  dwl = i;
}
void generator() {
  int p, i;
  for (i = 0; i < dwl; i++) {
    p = p + data[i];
  }
  p = p % 2;
  data[dwl] = p;
  dwl++;
}
void checker() {
  int i, s;
  for (i = 0; i < dwl; i++) {
    s = s + data[i];
  }
  s = s % 2;
  if (s == 0) {
    printf("Dataword Accepted ");
    dwl--;
  } else {
    printf("Dataword Rejected");
    dwl--;
  }
}
void transmission(int error) {
  int eprob, epos;
  srand(time(0));
  eprob = (rand() % 100) + 1;
  if (eprob <= error) {
    epos = rand() % dwl;
    data[epos] = 1 - data[epos];
  }
}
void main() {
  read_data();
  generator();
  transmission(100);
  checker();
  print_array();
}