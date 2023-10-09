#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int heapDelete();
extern void addHeap(int);
extern int heapSize();
extern void sort();

int main(int argc, char * argv[]){
  int value;

  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value); 
	addHeap(value);
  }  
	sort();
	heapDelete();                                

  exit(0);
}
