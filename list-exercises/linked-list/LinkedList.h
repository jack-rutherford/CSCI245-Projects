struct Node {
  struct Node* next;
  char* data;
};

struct LinkedList {
  struct Node* head;
};

/*
Returns 1 if the list named "list" contains a node whose value 
is sValue, 0 if not
*/
int contains (struct LinkedList* list, char* sValue);

struct LinkedList* copy (struct LinkedList* src);

void print(struct LinkedList* list);
struct LinkedList* create(char* data);
struct LinkedList* insertAfter(struct LinkedList* list, char* valueToFind, char* newValue);
