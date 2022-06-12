#include "basic.h"
#include "myALGO.h"

//clinic is a queue
HeadNode clinic[MAX_ROOM];

/*     sort compare functions     */
//AGE大到小，若一樣，病情1到5
int Cmp_age(const void *a, const void *b){
  Inform *p1 = (Inform *)a;
  Inform *p2 = (Inform *)b;
  if(p1->age == p2->age){
    return MAX_Cmpfunc(p1->situation_value, p2->situation_value);
  }
  return MIN_Cmpfunc(p1->age, p2->age);
}

//WEIGHT大到小，若一樣，AGE大到小
int Cmp_weight(const void *a, const void *b){
  Inform *p1 = (Inform *)a;
  Inform *p2 = (Inform *)b;
  if(p1->weight == p2->weight){
    return MIN_Cmpfunc(p1->age, p2->age);
  }
  return MIN_Cmpfunc(p1->weight, p2->weight);
}

//SITU小到大，若一樣，WEIGHT大到小
int Cmp_situ(const void *a, const void *b){
  Inform *p1 = (Inform *)a;
  Inform *p2 = (Inform *)b;
  if(p1->situation_value == p2->situation_value){
    return MIN_Cmpfunc(p1->weight, p2->weight);
  }
  return MAX_Cmpfunc(p1->situation_value, p2->situation_value);
}

//by Amos
/*    clinic select     */
int Situation_value(char *situ){
  if(strcmp(situ, "PANDEMIC") == 0)
    return 0;
  else if(strcmp(situ, "CARACCIDENT") == 0)
    return 1;
  else if(strcmp(situ, "PREGNANT") == 0)
    return 2;
  else if(strcmp(situ, "SCALD") == 0)
    return 3;
  else if(strcmp(situ, "INJURY") == 0)
    return 4;
  else if(strcmp(situ, "SICK") == 0)
    return 5;
  /*
  #if PANDEMIC_MODE
  else if(strcmp(situ, "PANDMIC") == 0)
    return 0;
  #endif
  */
}

/*
int Judge(int r1, int r2){
  
  #if PANDMIC_MODE
  
  return MIN_General(r1, r2);
  
  #elif !PANDMIC_MODE
  return MIN_General(MIN_General(r1, r2), 6);
  #endif
  
}
*/

void Select_room(Inform patient){
  int value = Situation_value(patient.situation);
  int clinic_num;
  //printf("%d\n", value);
  //get clinic room number
  switch (value){
  case 0:
    clinic_num = 0;
    break;
  case 1:
    clinic_num = (clinic[1].num <= clinic[2].num ? 1 : 2);
    break;
  case 2:
    clinic_num = (clinic[2].num <= clinic[3].num ? 2 : 3);
    break;
  case 3:
    clinic_num = (clinic[3].num <= clinic[4].num ? 3 : 4);
    break;
  case 4:
    clinic_num = (clinic[4].num <= clinic[5].num ? 4 : 5);
    break;
  case 5:
    clinic_num = (clinic[5].num <= clinic[1].num ? 5 : 1); 
    break;
  }
  //printf("%d\n", clinic_num);

  //push queue
  Push_room(clinic, clinic_num, patient);
  clinic[clinic_num].num++;
  //pop queue
  /*
  for(int i = 0; i < MAX_ROOM; i++){
    if(clinic[i].num != 0)
      Pop_room(clinic[i]);
  }
  */
}

void Room_init(){
  for(int i = 0; i < MAX_ROOM; i++){
    clinic[i].num = 0;
    clinic[i].first = NULL;
    clinic[i].last = NULL;
  }
}

void Push_room(HeadNode *clinic, int clinic_num, Inform patient){
  QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
  //new_node->patient = patient;
  new_node->patient.age = patient.age;
  strcpy(new_node->patient.name, patient.name);
  new_node->patient.number = patient.number;
  strcpy(new_node->patient.situation, patient.situation);
  new_node->patient.situation_value = patient.situation_value;
  new_node->patient.weight = patient.weight;
  new_node->next = NULL;
  new_node->prev = NULL;

  if(clinic[clinic_num].first == NULL){
    clinic[clinic_num].first = new_node;
    clinic[clinic_num].last = new_node;
  }
  else{
    QueueNode *temp = clinic[clinic_num].last;
    temp->next = new_node;
    new_node->prev = temp;
    clinic[clinic_num].last = new_node;
  }
  /*
  QueueNode *cur = clinic[clinic_num].first;
  while(cur != NULL){
    printf("%s\t", cur->patient.name);
    cur = cur->next;
  }
  printf("\n");
  */
}

void Pop_room(HeadNode room){
  QueueNode *temp = room.last;
  //room.last pop
  room.last = temp->prev;
  free(temp);

  temp = room.last;
  temp->next = NULL;
  
  room.num--;
}

void Pop_all(){
  for(int i = 0; i < MAX_ROOM; i++){
    QueueNode *cur = clinic[i].first;
    while(cur != NULL){
      QueueNode *temp = cur;
      cur = cur->next;
      free(temp);
    }
  }
}
