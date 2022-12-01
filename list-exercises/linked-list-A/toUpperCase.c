#include <toUpperCase.h>
#include "LinkedList.h"

void toUpperCase(struct Node* node){
  for(int i = 0; node->data[i] != '\0'; i++){
    node->data[i] = toupper(node->data[i]);
  }
}