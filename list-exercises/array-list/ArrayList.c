#include <stdlib.h>
#include "ArrayList.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

/*
  Retrieves the struct stored in the list at position index
  Returns a struct data object whose valid field is false if the index is outside the current bounds of the list
*/
struct data get(struct list* lst, int index) {
	
	struct data value;
	value.valid = 0;
	value.value = 0;
	
	if(index < 0 || index >= lst->capacity){
		return value;
	}
	else{
		return lst->address[index];
	}
	return value;
}

struct list* initialize(int initialSize){
	struct list* newList = malloc(sizeof(struct list));
	newList->capacity = initialSize;
	newList->address = malloc(initialSize * sizeof(struct data));

	for(int i = 0; i < initialSize; i++){
		newList->address[i].valid = 0;
	}
	return newList;
}

/*
  Sets the value stored at the given index to the requested value 
  If index is beyond the bounds of the current array, a new chunk of 
  memory is allocated, and the contents of the old array are copied 
  to the new array before setting the requested value
*/
void set(struct list* lst, int index, int value){
	if(index < lst->capacity){
		lst->address[index].valid = 1;
		lst->address[index].value = value;
	}
	else {
		// Allocate enough memory so index is valid
		struct data* newArray = malloc(index*2*sizeof(struct data));
		
		// Copy all the existing elements form the old array to the new array
		for(int i = 0; i < lst->capacity; i++){
			newArray[i] = lst->address[i];
		}
		// Invalidate elements beyond original capacity
		for(int i = lst->capacity; i < 2*index; i++){
			newArray[i].valid = 0;
		}
		// Set the value at index to desired value
		newArray[index].value = value;
		newArray[index].valid = 1;
		// Free the memeory associated with the old array
		free(lst->address);
		lst->address = newArray;
		lst->capacity = index*2;
	}

}

/*
  Reduces the capacity of the list pointed to by lst 
  to the given value; any data that exists with index -capacity- or 
  greater are lost
*/
void truncate(struct list* lst, int capacity){
	if(lst->capacity > capacity){
		struct data* newArray = malloc(capacity*sizeof(struct data));
		for(int i = 0; i < capacity; i++){
			newArray[i] = lst->address[i];
		}
		free(lst->address);
		lst->address = newArray;
		lst->capacity = capacity;
	}
}

/*
  Reduces the amount of memory being used by the list to match its capacity,
  by creating a new block of memory to hold exactly the right number of 
  elements, copying the elements of the existing list that have been set,
  and then freeing up the memory previously allocated to the list
*/
void compact (struct list* lst){
	int j = 0;
	while(lst->address[j].valid == 1){
		j++;
	}
	int newCapacity = j;
	struct data* newArray = malloc(newCapacity*sizeof(struct data));

	int index = 0;
	for(int i = 0; i < lst->capacity; i++){
		if(lst->address[i].valid == 1){
			newArray[i] = lst->address[i];
			index++;
		}
	}
	free(lst->address);
	lst->address = newArray;
	lst->capacity = newCapacity;
}