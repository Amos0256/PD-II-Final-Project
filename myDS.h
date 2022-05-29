#ifndef MYDS_H
#define MYDS_H

void Create(Node **first, Node **last);
void Add(Node **head, Node **last, Inform patient);
void Delete(Node *head, char *name);
Node *Search(Node *head, char *name);
void Print(Node *node);
void Print_ALL(Node *head);
void Delete_ALL(Node *head);
void InsertionSort(Node **head);
void Insert(Node *node, Node **sorted);

#endif