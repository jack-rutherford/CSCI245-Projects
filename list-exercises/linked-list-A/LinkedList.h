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

/**
 Deletes the node in the list with value "value"
 Returns 0 if such a node cannot be found; otherwise
 returns 1
**/
int delete(struct LinkedList* list, char* value);

/**
 Visits each node of the list, calling the function
 pointed to by "visitFunc" for each node
**/
void visit(struct LinkedList* list,
void (*visitFunc) (struct Node* value));

void print(struct LinkedList* list);
struct LinkedList* create(char* data);
struct LinkedList* insertAfter(struct LinkedList* list, char* valueToFind, char* newValue);
