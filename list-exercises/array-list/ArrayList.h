struct data {
  char valid;
  int value;
};

struct list {
  struct data* address;  
  int capacity;
 };

/*
  Sets the value stored at the given index to the requested value 
  If index is beyond the bounds of the current array, a new chunk of 
  memory is allocated, and the contents of the old array are copied 
  to the new array before setting the requested value
*/
void set(struct list* lst, int index, int value);

/*
  Retrieves the struct stored in the list at position index
  Returns a struct data object whose valid field is false if the index is outside the current bounds of the list
*/
struct data get(struct list* lst, int index);

/*
  Creates a new list capable of holding the number of entries
  specified in the parameter initialSize, marking all of the 
  entries as invalid
*/
struct list* initialize(int initialSize);

/*
  Reduces the capacity of the list pointed to by lst 
  to the given value; any data that exists with index -capacity- or 
  greater are lost
*/
void truncate(struct list* lst, int capacity);

/*
  Reduces the amount of memory being used by the list to match its capacity,
  by creating a new block of memory to hold exactly the right number of 
  elements, copying the elements of the existing list that have been set,
  and then freeing up the memory previously allocated to the list
*/
void compact (struct list* lst);
