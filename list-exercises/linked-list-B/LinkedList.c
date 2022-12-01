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
  struct Node* tmp = src->head;
  struct LinkedList* lst = create(tmp->data);
  struct Node* tail = src->head->next;
  while(tail != NULL){
    insertAfter(lst, tmp->data, tail->data);
    tmp = tail;
    tail = tail->next;
  }
  return lst;
}

/**
 Inserts a new node with value "value" into the list
referenced by "list" so that the new node comes before 
 the node with value "sValue"
 Returns 0 if no node with value "sValue" can be found 
 in the list. Returns -1 if no memory can be allocated
 for a new node, and 1 if the new node is created
**/ 
int insertBefore (struct LinkedList* list, char* sValue, char* value){
  int result = contains(list, sValue);
  if(result == 1){
    struct Node* nNode = createNode(value);
    if(nNode == NULL){
      // printf("No memory can be allocated for new node");
      return -1;
    }

    if(strcmp(list->head->data, sValue) == 0){
      nNode->next = list->head;
      list->head = nNode;
      return 1;
    }

    struct Node* tmp = list->head->next;
    struct Node* pNode = list->head;
    while (tmp != NULL) {
      if(strcmp(tmp->data, sValue) == 0){
        nNode->next = tmp;
        pNode->next = nNode;
        return 1; //contains the node
      }
      pNode = tmp;
      tmp = tmp->next;
    }
    return 1;
  }
  else{
    // printf("No node with value %s could be found\n", value);
    return 0;
  }
}

/**
 Deletes the node in the list with value "value"
 Returns 0 if such a node cannot be found; otherwise
 returns 1
**/
int delete(struct LinkedList* list, char* value){
  int result = contains(list, value);
  if(result == 1){
    //check head first
    if(strcmp(list->head->data, value) == 0){
      list->head = list->head->next;
      list->head->next = NULL;
      free(list->head);
      return 1; //head is the node you're looking for, deleted
    }

    //start from second node, previous node is head
    struct Node* tmp = list->head->next;
    struct Node* pNode = list->head;
    while (tmp != NULL) {
      if(strcmp(tmp->data, value) == 0){
        pNode->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
        return 1; //contains the node, deleted
      }
      tmp = tmp->next;
    }
  }
  else{
    return 0; //node not found
  }
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
