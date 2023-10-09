#include <stdio.h>
#include <stdlib.h>
void garbageState(); 
void garbageCheck(); 
void deleteCheck();
	struct state  
	{
		struct state *next0;
		struct state *next1;
		char name;
		int garbage;
		int delete;
	};
	int numS=8;		
	struct state *temp;	
	
void deleteCheck(struct state s[]){
	
	for (int i = 0; i < 8; i++){
		if(s[i].garbage == 1){
			s[i].garbage = 0;
			s[i].delete = 1;
		}
		else if (s[i].garbage == 1 && s[i].delete == 0){
		s[i].delete = 0;
		}
	}
}	
	
	
void garbageState(struct state s[],struct state *current){ 
   for (int i = 0; i < 8; i++){
	   if (s[i].delete != 1){
		s[i].garbage = 1;	
	  }
	}
    garbageCheck(s,current);
}		

void garbageCheck(struct state s[],struct state *current){
	current->garbage=0;
	if(current ->next0 ->garbage == 1){
		garbageCheck(s,current->next0);
	}
	if(current ->next1 ->garbage == 1){
		garbageCheck(s,current->next1);
	}
}
	
	
int main(){
	FILE *ptr;
	char ch[50];
	char l;

	ptr = fopen("letterList.txt", "r");

	if (NULL == ptr)
	{
		printf("file can't be opened \n");
	}

	int line = 0;

	do  //Reads file containing FSM Order
	{
		l = fgetc(ptr);
		if (l == 'A' || l == 'B' || l == 'C' || l == 'D' || l == 'E' || l == 'F' || l == 'G' || l == 'H')
		{
			ch[line] = l;
			line++;
		}
	} while (l != EOF);

	fclose(ptr);
	
	int i = 0,k=0,j=0;
	
	struct state s[8];
	struct state *current;
	
	while (i < (line)){       //Puts the FSM structs into Array of states
		s[i/3].name = ch[i];
		i+=3;
	}
	
	while(j < (line)) {	        //Assigns the next state when input is 0
        while (k < (line/3)){	
			if (s[k].name == ch[j+1] ){
				s[j/3].next0 = &s[k];
				j=j+3;
				k=0;
				break;
			}
			k=k+1;
		}
	} 
	
	k=0,j=0;
	while(j < (line)) {	       //Assigns the next state when input is 1
        while (k < (line/3)){	
			if (s[k].name == ch[j+2] ){
				s[j/3].next1 = &s[k];
				j=j+3;
				k=0;
				break;
			}
			k=k+1;
		}
	} 
	
	current = &s[0];
	
	
	for (int i = 0; i < 8; i++){
			s[i].delete = 0;
	}
       
    int u =0;
    
    while(u == 0){ 
    char inp[6];
   	
    printf("\nCurrent State: %c",current->name);
    printf("\nEnter command (enter 'e' to exit):");
    fgets(inp,6,stdin); 
    
    switch(inp[0]){      
        case'c':{    //    (c 0 A  change the current next set at 0 to A)
        struct state *temp;
        int bool =0;
			
		   for (int i = 0; i < numS; i++){
				if(s[i].delete == 1){
					if (inp[4] == s[i].name){
						bool = 1;
						break;
					}
				}
			}
			if(bool == 1){
				printf("\nYou can't change to this state");
				break;
			}
        
            for(int r=0; r < numS; r++){
                if(s[r].name == inp[4]){
                    temp = &s[r];
                    break;
                }
            }
			
           for(int r=0; r < numS; r++){
           
             if (current == &s[r]){                                                                           		
                if (inp[2] == '0'){
                    s[r].next0 = temp;
                }
                else if (inp[2] == '1' && s[r].delete == 0){
                    s[r].next1 = temp;
                }
                else{
                    printf("Invalid Input");
                }
              }
            }
                                             
        break;
        }
        
        case'g':{
			temp = current;
			garbageState(s,current);	
			int x=0;
			
			for (int i = 0; i < numS; i++){	
				if(s[i].garbage == 1){
					x++;
				}
			}	
			if(x == 0){
				printf("\nNo Garbage");
			}
			else{
				printf("\nGarbage:");
				for (int i = 0; i < numS; i++){	
					if(s[i].garbage == 1 && s[i].delete != 1){
						printf("%c ",s[i].name);
					}
				}	
			}
			
		break;    
        }
        
        case'p':{
         for (int j = 0; j < numS; j++){  
		    if (s[j].delete == 0){   
				printf("\n%c %c %c",s[j].name,(s[j].next0)->name, (s[j].next1)->name);
			}
         }
		 break;
		}
		
		case 'd':{ 
			
			garbageState(s,current);	
			int x=0;
			for (int i = 0; i < numS; i++){	
				if(s[i].garbage == 1){
					x++;
				}
			}

			if(x == 0){
				printf("\nNo states deleted.");
				break;
			}
			if (inp[2] == 'A' || inp[2] == 'A' || inp[2] == 'B' || inp[2] == 'C' || inp[2] == 'D' || inp[2] == 'E' || inp[2] == 'F' || inp[2] == 'G' || inp[2] == 'H'){
				 	
				for (int i = 0; i < numS; i++){
					if (s[i].name == inp[2]){
						if(s[i].garbage == 1){
							s[i].delete = 1;
							printf("\nDeleted");
							break;
						}
						else{
							printf("Not delteted");
						}
					}
				} 	
				
			}	
			else{
			int y=0;
			int del[x];
			
			for (int i = 0; i < numS; i++){	
				if(s[i].garbage == 1 && s[i].delete == 0){
					del[y] = s[i].name;
					y++;
				}
			}
						
			deleteCheck(s);		
	
			printf("\nStates Left:");
			for (int i = 0; i < numS; i++){
				if(s[i].delete == 0){
					printf("%c ", s[i].name);
				}
			
			}
			
		printf("\nDeleted:");
		for (int r = 0; r < y; r++){
				printf("%c ", del[r]);
		}
		}
			    
		 break;
		}
        
        case'0':{
            current = (current->next0);
        break;
        }

        
        
        case'1':{
            current = (current->next1);
            break;
        case'e':{
		   u =1;
		   break;
		}
		
        default:{
            printf("\nWrong Input choice.... Try again");
        }
        }
    }
    printf("\n");
}    

	return 0;
}


