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

int main(){
  int mode;
  fprintf(stderr, "[1]input by terminal [2]input by file:\n");
  scanf("%d", &mode);
  
  //terminal input
  if(mode == 1){
    fprintf(stderr, "please input number of input:\n");
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++){
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
    }
  }
  //file input
  else if(mode == 2){
    //linked list database
    File_Input_DB();

    //linked list
    Add(&first, &last, last_DB->field);

    num = num_DB;
    //copy into data
    for(int i = 0; i < num; i++){
      data[i].age = last->field.age;
      strcpy(data[i].name, last->field.name);
      strcpy(data[i].situation, last->field.situation);
      data[i].weight = last->field.weight;
      data[i].number = last->field.number;
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
  
  //output
  int output;
  fprintf(stderr, "[1]database [2]clinic list:\n");
  scanf("%d", &output);

  if(output == 1)
    File_Output_DB();
  else if(output == 2)
    Print_ALL(head);

  return 0;
}

/*
void linked_list(Node* first, Node* head, int num){
    //Amos help!!!
    for(int i=0; i<num; i++){
        Node* tmp = malloc(sizeof(Node));
        Create(first, head);
    }
    InsertionSort(&head);
}*/