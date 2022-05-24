#include "basic.h"
#include "myALGO.h"

int room[MAX_ROOM] = {0};

/*     sort compare functions     */
//AGE大到小，若一樣，病情1到5
int Cmp_age(const void* a, const void* b){
  Inform* p1 = (Inform*)a;
  Inform* p2 = (Inform*)b;
  if(p1->age == p2->age){
    return MAX_Cmpfunc(p1->situation_value, p2->situation_value);
  }
  return MIN_Cmpfunc(p1->age, p2->age);
}

//WEIGHT大到小，若一樣，AGE大到小
int Cmp_weight(const void* a, const void* b){
  Inform* p1 = (Inform*)a;
  Inform* p2 = (Inform*)b;
  if(p1->weight == p2->weight){
    return MIN_Cmpfunc(p1->age, p2->age);
  }
  return MIN_Cmpfunc(p1->weight, p2->weight);
}

//SITU小到大，若一樣，WEIGHT大到小
int Cmp_situation(const void* a, const void* b){
  Inform* p1 = (Inform*)a;
  Inform* p2 = (Inform*)b;
  if(p1->situation_value == p2->situation_value){
    return MIN_Cmpfunc(p1->weight, p2->weight);
  }
  return MAX_Cmpfunc(p1->situation_value, p2->situation_value);
}

/*    clinic select     */
int Situation_value(char* situ){
  if(strcmp(situ, "CARACCIDENT") == 0)
    return 1;
  else if(strcmp(situ, "PREGNANT") == 0)
    return 2;
  else if(strcmp(situ, "SCALD") == 0)
    return 3;
  else if(strcmp(situ, "INJURY") == 0)
    return 4;
  else if(strcmp(situ, "SICK") == 0)
    return 5;
  #if PANDEMIC_MODE
  else if(strcmp(situ, "PANDMIC") == 0)
    return 0;
  #endif
}

int Judge(int r1, int r2){
  #if PANDMIC_MODE
  return MIN(r1, r2);
  #elif !PANDMIC_MODE
  return MIN_General(MIN_General(r1, r2), 6);
  #endif
}

void Select_room(Inform patient){
  int value = Situation_value(patient.situation);
  int clinic_num;
  switch (value){
  case 0:
    clinic_num = Judge(6, 6);
    break;
  case 1:
    clinic_num = Judge(0, 4);
    break;
  case 2:
    clinic_num = Judge(0, 1);
    break;
  case 3:
    clinic_num = Judge(1, 2);
    break;
  case 4:
    clinic_num = Judge(2, 3);
    break;
  case 5:
    clinic_num = Judge(3, 4); 
    break;
  }
  room[clinic_num]++;
}