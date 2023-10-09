#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int top = 0;
static char *stack[100];
char * dummya;


char *  pop(){

	if(top  == -1){
	fprintf(stderr,"Invalid error");
	}

	dummya = stack[top-1];

	top = top - 1;
    printf("popped\n");
    printf("top = %d\n",top);
	printf("\n");
   return dummya;
}

void push(char * thing2push){
	if(top  == 99){
	fprintf(stderr,"Invalid error");
	}
	stack[top] = thing2push;
	printf("\n%s ",stack[top]);
	top++;
	printf("pushed\n");
	printf("top = %d\n",top);
	printf("\n");
}

int isEmpty(){
if(top == 0){
return 1;
}
return 0; 
}
