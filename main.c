#include "basic.h"
#include "database.h"
#include "myALGO.h"
#include "myDS.h"

#include <stdio.h>
#include <stdlib.h>

void input_array(int num, Inform sort[]){
    for(int i=0; i<num; i++){
        scanf("%s %d %f %d %s %d", &sort[i].name, &sort[i].age, &sort[i].weight, &sort[i].number, &sort[i].situation, &sort[i].situation_value);
    }
    //sort
    int sort_class;
    printf("[1]age [2]weight [3]situation:\n");
    scanf("%d", &sort_class);
    if(sort_class==1){
        qsort(sort, 100000, sizeof(sort[0]), Cmp_age);
    }
    else if(sort_class==2){
        qsort(sort, 100000, sizeof(sort[0]), Cmp_weight);
    }
    else if(sort_class==3){
        qsort(sort, 100000, sizeof(sort[0]), Cmp_situ);
    }
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
int main(){
	int input, output, num;
    Inform sort[100000];
    Node* first = NULL;
    Node* head = NULL;
    printf("[1]input by terminal [2]input by file:\n");
    scanf("%d", &input);
    scanf("%d", &num);
	if(input==1){
        input_array(num, sort);
    }
    else if(input==2){
        File_Input_DB();
    }
    //linked_list(first, head);
    for(int i=0; i<num; i++){
        Select_room(sort[i]);
    }
    
    printf("[1]database [2]clinic list:\n");
    scanf("%d", &output);
    if(output==1){
        File_Output_DB();
    }
    else if(output==2){
        Print_ALL(head);
    }

	return 0;	
}