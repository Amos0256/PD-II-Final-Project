#ifndef MYALGO_H
#define MYALGO_H

#define MAX_ROOM 6
//#define PANDEMIC_MODE 0
#define MAX_Cmpfunc(a, b) ((a) >= (b) ? 1 : -1)
#define MIN_Cmpfunc(a, b) ((a) <= (b) ? 1 : -1)
#define MIN_General(a, b) ((a) <= (b) ? (a) : (b))

typedef struct{
  Inform patient;
  struct QueueNode *next;
  struct QueueNode *prev;
}QueueNode;

typedef struct{
  int num;
  struct QueueNode *first;
  struct QueueNode *last;
}HeadNode;

int Cmp_age(const void *a, const void *b);
int Cmp_weight(const void *a, const void *b);
int Cmp_situ(const void *a, const void *b);
int Situation_value(char *situ);
int Judge(int r1, int r2);
void Select_room(Inform patient);
void Push_room(HeadNode *clinic, int clinic_num, Inform patient);
void Pop_room(HeadNode room);
void Pop_all();

#endif