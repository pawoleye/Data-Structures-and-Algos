#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
extern char *  pop();
extern void push(char*);
extern int isEmpty();

int main(int argc, char * argv[]){
  char ch;
  int i,j,size;
  char* tem;
  while ((ch = getchar()) != EOF) {

 if(ch == '<'){
   tem = (char*) malloc (20* sizeof (char));
    for(i=0;i<20;i++){
      scanf("%c",tem + i);
      if(tem[0] == '/'){
         size=1;
       }
     if(tem[i] == '>'){
        tem[i] = '\0';
        break;
       }
    }

if(size!= 1){
   push(tem);
}
for(i = 0; tem[i] != '\0'; ++i){
        while (!( (tem[i] >= 'a' && tem[i] <= 'z') || (tem[i] >= 'A' && tem[i] <= 'Z') || tem[i] == '\0') )
        {
            for(j = i; tem[j] != '\0'; ++j)
            {
                tem[j] = tem[j+1];
            }
            tem[j] = '\0'; 
        }
    }
if(size==1){
    size=0;
if(strcmp(tem,pop())!=0){
    printf("Invalid error\n");
    exit(0);
}
}

}

}
	if(isEmpty() == 1){
        printf("Valid");
        exit(1);
    }
    else{
        printf("Not Valid");
    exit(0);
	}

exit(0);
}
