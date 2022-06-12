#ifndef basic_H
#define basic_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 100

typedef struct{
  char name[20];
  int age;
  float weight;
  int number;  //chart No.
  char situation[20];
  int situation_value;
}Inform;

typedef struct{
  Inform field;
  struct Node *next;
}Node;

#endif