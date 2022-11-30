#include "LinkedList.h"
#include <stdio.h>

int main (int argc, char** argv) {
  struct LinkedList* list = create("Hello");
  insertAfter(list, "Hello", " ");
  insertAfter(list, " ", "world");
  insertAfter(list, "world", "\n");

  //task 2
  print(list);

  int w = contains(list, "Hello");
  int w2 = contains(list, " ");
  int w3 = contains(list, "world");
  printf("Result of contains:\nHello\t-> %d\n\" \"\t-> %d\nworld\t-> %d\n", w, w2, w3);

  int w4 = contains(list, "Goodbye");
  printf("\nResult of contains:\nGoodbye\t-> %d\n\n", w4);

  struct LinkedList* lstCopy = copy(list);
  insertAfter(lstCopy, " ", "new");
  insertAfter(lstCopy, "new", " ");
  printf("New list: ");
  print(lstCopy);

  printf("\nOld list: ");
  print(list);

}