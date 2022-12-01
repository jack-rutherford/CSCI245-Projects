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

/**
 Inserts a new node with value "value" into the list
referenced by "list" so that the new node comes before 
 the node with value "sValue"
 Returns 0 if no node with value "sValue" can be found 
 in the list. Returns -1 if no memory can be allocated
 for a new node, and 1 if the new node is created
**/ 
int insertBefore (struct LinkedList* list, char* sValue, char* value);

void print(struct LinkedList* list);
struct LinkedList* create(char* data);
struct LinkedList* insertAfter(struct LinkedList* list, char* valueToFind, char* newValue);
