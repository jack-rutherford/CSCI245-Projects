#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

void printSeparator () {
	int i = 0;
	for (i = 0; i < 80; i++) {
		printf ("=");
	}	
	printf ("\n");
}

int main (int argc, char** argv) {
	int numItems;
	struct list *lst, *secondList;
	int i;
	
	printf ("How many items do you want the list to be able to hold initially?\n");
	scanf ("%d", &numItems);
	
	lst = initialize(numItems);
	
	printSeparator();
	
	set(lst,0, 100);
	set(lst, numItems-1, 200);
	
    printf ("Printing list after setting 1st and last element of the list to 100 and 200\n");
	printf ("List allocated at %p\n", lst->address);
	printf ("%d: %d \n", 0, get(lst, 0).value);
	printf ("%d: %d \n", numItems-1, get(lst, numItems-1).value);
	printSeparator ();

	printf ("Attempting to print out value of item %d\n", numItems);
	struct data pastBounds = get(lst, numItems);
	if (pastBounds.valid) {
      printf("Oops, value is valid but shouldn't be: %d\n", pastBounds.value);
	}
	else {
      printf ("There is no value stored at index %d\n", numItems);
	}	
	printSeparator();

	printf("Printing list after using set to set the value of item %d to 300\n", numItems);
	set(lst, numItems, 300);
	printf ("List allocated at %p\n", lst->address);
	printf ("%d: %d \n", 0, get(lst, 0).value);
	printf ("%d: %d \n", numItems-1, get(lst, numItems-1).value);
	printf ("%d: %d \n", numItems, get(lst, numItems).value);
	printSeparator();

	truncate(lst, 2);
	printf ("After truncating the list to size 2:\n");
	printf ("List allocated at %p\n", lst->address);
	printf ("%d: %d \n", 0, get(lst, 0).value);
	
	if (get(lst, 1).valid) {
		printf ("Oops, element at index 1 is valid after truncating list to size 2\n");
	}
	
	if (get(lst, numItems-1).valid) {
		printf ("Oops, after truncating to size 2 the index %d is still valid", numItems-1);
	}
	else {
		printf ("There is no longer a value stored at index %d after truncating the list to size 2\n", numItems-1);
	}	
	printSeparator();

	secondList = initialize(100);
	set (secondList, 0, 1);
	set (secondList, 50, 2);
	set (secondList, 99, 3);
	printf("Before compaction of second list:\n");
	printf ("Second list allocated at %p\n", secondList->address);
	printf("Capacity: %d\n", secondList->capacity);
	printf("%d: %d\n", 0, get(secondList, 0).value);
	printf("%d: %d\n", 50, get(secondList, 50).value);
	printf("%d: %d\n", 99, get(secondList, 99).value);
	printSeparator();

	compact(secondList);
	printf("After compaction:\n");
	printf ("Second list allocated at %p\n", secondList->address);
	printf("Capacity: %d\n", secondList->capacity);
	for (i = 0; i < 3; i++) {
		printf("%d: %d\n", i, get(secondList, i).value);
	}
	printSeparator();

	//  Make sure that calling compact on an already compacted list works correctly
	compact(secondList);
	printf("After 2nd compaction:\n");
	printf ("Second list allocated at %p\n", secondList->address);
	printf("Capacity: %d\n", secondList->capacity);
	for (i = 0; i < 3; i++) {
		printf("%d: %d\n", i, get(secondList, i).value);
	}
	printSeparator();
}
