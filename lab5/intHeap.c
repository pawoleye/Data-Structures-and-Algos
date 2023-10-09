/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
static int size=0;
static int heap[100];
extern int pop();
extern void push(int);

void sort()
{
  int j,x,i;

    for(int i = 0; i < size; i++){
        j = i - 1;
        x = heap[i];
        while(j>=0 && heap[j]>x){
            heap[j+1] = heap[j];
            j--;
        }
        heap[j+1] = x;
    }

	for(i=size-1; i>=0; i--){
	   printf("<node id = '%d'>",heap[i]);
	   if(i==1){
		printf("</node></node>");
		break;
		}
   		if(i<size-1 && (i-2 >= 0 || i-3 >= 0)){
    		 printf("<node id '%d'>",heap[i-2]);
     		printf("</node></node>");
		}
	} 
		
}

int heapDelete(){
int i,large;
i = size;
while (size > 0){
large = heap[size-1];
push(large);
size--;
}
printf("\n");

while (i > 0){
pop();
i--;
} 
return large;  
}

/*
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add){
heap[size] = thing2add;
size++;
printf("\n");
}

/*
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;  //A dummy return statement
}
