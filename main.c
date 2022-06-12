#include "basic.h"
#include "database.h"
#include "myALGO.h"
#include "myDS.h"

Node *first = NULL;
Node *last = NULL;
extern Node *first_DB;
extern Node *last_DB;
extern num_DB;
Inform data[MAX_DATA];
extern HeadNode clinic[MAX_ROOM];
int num = 0;

int main(){
  int mode;
  fprintf(stderr, "[1]input by terminal [2]input by file:\n");
  scanf("%d", &mode);
  
  //terminal input
  if(mode == 1){
    int input_num;
    fprintf(stderr, "please input number of input:\n");
    scanf("%d", &input_num);
    
    fprintf(stderr, "Age\tName\tSituation\tWeight\n");
    for(int i = 0; i < input_num; i++){
      //linked list
      Create(&first, &last);

      //copy into data
      data[i].age = last->field.age;
      strcpy(data[i].name, last->field.name);
      strcpy(data[i].situation, last->field.situation);
      data[i].weight = last->field.weight;
      data[i].number = last->field.number;

      //linked list database
      Add_DB(data[i]);
      //printf("num = %d\n", num);
    }
  }
  //file input
  else if(mode == 2){
    //linked list database
    File_Input_DB();

    //linked list
    Add(&first, &last, last_DB->field);

    //printf("num = %d\n", num);
    //copy into data
    Node *cur = first_DB;
    //printf("%d\n", num);
    while(cur != NULL){
      data[num].age = cur->field.age;
      strcpy(data[num].name, cur->field.name);
      strcpy(data[num].situation, cur->field.situation);
      data[num].weight = cur->field.weight;
      data[num].number = cur->field.number;
      cur = cur->next;
      num++;
    }
  }

  //sort priority
  int priority;
  fprintf(stderr, "[1]age [2]weight [3]situation:\n");
  scanf("%d", &priority);
  if(priority == 1)
    qsort(data, num, sizeof(Inform), Cmp_age);
  else if(priority == 2)
    qsort(data, num, sizeof(Inform), Cmp_weight);
  else if(priority == 3)
    qsort(data, num, sizeof(Inform), Cmp_situ);

  //clinic select
  Room_init();
  for(int i = 0; i < num; i++)
    Select_room(data[i]);
  /*
  for(int i = 0;i < MAX_ROOM; i++)
    printf("%d\t", clinic[i].num);
  */

  fprintf(stderr, "Check currently clinic? [1] Yes [2] No\n");
  int c;
  scanf("%d", &c);
  if(c == 1){
    for(int i = 0; i < MAX_ROOM; i++){
      printf("Waiting list of clinic %d:\n", i+1);
      int count = 0;
      QueueNode *cur = clinic[i].first;
      while(cur != NULL){
        printf("%d: %s\n", ++count, cur->patient.name);
        cur = cur->next;
      }
      printf("\n");
    }
  }

  Pop_all();
  
  //output
  int output;
  fprintf(stderr, "Output database to [1]file [2]terminal:\n");
  scanf("%d", &output);

  if(output == 1)
    File_Output_DB();
  else if(output == 2){
    Print_ALL(first_DB);
  }

  return 0;
}

