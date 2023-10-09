#include <stdlib.h>
#include "towers.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int n=3;
    int from=1 ;
    int dest=2;
   
    if ( argc == 1){
        n = 3;
        from=1;
        dest =2;
    }
    else if (argc == 2) {
        n = atoi(argv[1]);
    }
    else if (argc > 3){
        n = atoi(argv[1]);
        from = atoi(argv[2]);
        dest = atoi(argv[3]);
        if (from > 3 || dest > 3 || from == dest){
          fprintf(stderr,"Incorrect Input");
           exit(1);  
        }
    }
    else{
        fprintf(stderr,"Incorrect Input");
        exit(1);
    }

    towers(n, from, dest);
    exit(0);
}

