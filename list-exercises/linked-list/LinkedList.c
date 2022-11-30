#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LinkedList.h"

void print(struct LinkedList* list){
  struct Node* tmp = list->head;
  while (tmp != NULL) {
    printf ("%s", tmp->data);
    tmp = tmp->next;
  }
}

/*
Returns 1 if the list named "list" contains a node whose value 
is sValue, 0 if not
*/
int contains (struct LinkedList* list, char* sValue){
  struct Node* tmp = list->head;
  while (tmp != NULL) {
    if(strcmp(tmp->data, sValue) == 0){
      return 1; //contains the node
    }
    tmp = tmp->next;
  }
  return 0; //does not contain the node
}

struct LinkedList* copy (struct LinkedList* src) {
  struct Node* tmp = createNode(src->head->data);
  struct LinkedList* lst = create(tmp->data);
  struct Node* tail = src->head->next;
  while(tail != NULL){
    insertAfter(lst, tmp->data, tail->data);
    tmp = tail;
    tail = tail->next;
  }
  return lst;
}

struct Node* createNode (char* data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  //  Make sure memory was successfully allocated for the new node
  if (node == NULL) {
	  return NULL;
  }
  node->next = NULL;
  node->data = strdup(data);
  return node;
}

struct LinkedList* create (char* data) {
  struct LinkedList* newList = (struct LinkedList*) malloc(sizeof(struct LinkedList));
  if (newList != NULL) {
    newList->head = createNode(data);
  }
  return newList;
}

struct LinkedList* insertAfter (struct LinkedList* list, char* insertNodeValue, char* newValue) {
  struct Node* currentNode = list->head;
  while (currentNode != NULL && strcmp(currentNode->data, insertNodeValue) != 0) {
    currentNode = currentNode->next; 
  }
  
  //  If we didn't find the value, return NULL to indicate that fact
  if (currentNode == NULL) {
    return NULL;
  }
  
  //  Otherwise, create a new node, and set up the pointers appropriately
  struct Node* newNode = createNode(newValue);
  if (newNode != NULL) {
    newNode->next = currentNode->next;
    currentNode->next = newNode;
  }
  return list;
}
