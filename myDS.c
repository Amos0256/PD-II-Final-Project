#include "basic.h"
#include "myDS.h"

//create patient informations (input)
void Create(Node **first, Node **last){
  srand(time(NULL));
  Inform input;
  scanf("%d %s %s %f", &input.age, input.name, input.situation, &input.weight);
  input.number = rand() % (100 + 1);
  Add(first, last, input);
}

//seen the new patient informations as a node
//add new node to linked list 
void Add(Node **head, Node **last, Inform patient){
  Node *new_node = (Node *)malloc(sizeof(Node));
  //copy the patient informations into node
  new_node->field.age = patient.age;
  strcpy(new_node->field.name, patient.name);
  new_node->field.number = patient.number;
  strcpy(new_node->field.situation, patient.situation);
  new_node->field.weight = patient.weight;
  new_node->next = NULL;
  
  //first node
  if(*head == NULL){
    *head = new_node;
    *last = new_node;
  }
  //not first node
  else{
    Node *temp = *last;
    temp->next = new_node;
    *last = new_node;
  }
}

//delete the node
//patient leave the hospital
void Delete(Node *head, char *name){
  Node *cur = head;
  Node *prev;
  while(cur != NULL && (strcmp(cur->field.name, name) != 0)){
    prev = cur;
    cur = cur->next;
  }

  if(cur == NULL)
    printf("Patient Not Exist!!!\n");
  else{
    prev->next = cur->next;
    free(cur);
  }
}

//search the node by giving the patient name
Node *Search(Node *head, char *name){
  Node *cur = head;
  while(cur->next != NULL){
    if(strcmp(cur->field.name, name) == 0)
      return cur;
    cur = cur->next;
  } 
  return NULL;
}

//print the patient informations / node
void Print(Node *node){
  if(node == NULL)
    printf("Patient Not Exist!!!\n");
  else{
    printf("Name: %s\n", node->field.name);
    printf("Age: %d\n", node->field.age);
    printf("Weight: %.2f\n", node->field.weight);
    printf("Number: %d\n", node->field.number);
    printf("Situation: %s\n", node->field.situation);
  }
}

//print all of patient informations / node
void Print_ALL(Node *head){
  Node *cur = head;
  while(cur != NULL){
    Print(cur);
    cur = cur->next;
  }
  printf("\n");
}

//delete all of patient informations / node
void Delete_ALL(Node *head){
  Node *cur = head;
  while(cur != NULL){
    Node *temp = cur;
    cur = cur->next;
    free(temp);
  }
}

//linked list insertion sort
void InsertionSort(Node **head){
  //sorted linked list
  Node *sorted = NULL;
  Node *cur = *head;
  while(cur != NULL){
    Node *next = cur->next;
    Insert(cur, &sorted);
    cur = next;
  }
  *head = sorted;
}

//insert function
void Insert(Node *node, Node **sorted){
  //1st insertion sort or number of node is larger than first node of sorted
  if(*sorted == NULL || ((*sorted)->field.number >= node->field.number)){
    node->next = *sorted;
    *sorted = node;
  }
  //number of node is smaller than first node
  else{
    Node *cur = *sorted;
    Node *prev;
    //find the correct place
    while(cur != NULL && cur->field.number < node->field.number){
      prev = cur;
      cur = cur->next;
    }
    //node is not the last
    if(cur != NULL){
      prev->next = node;
      node->next = cur;
    }
    //node is the last
    else{
      prev->next = node;
      node->next = NULL;
    }
  }
}