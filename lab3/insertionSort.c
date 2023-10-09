#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last){
    int j, key;

  for (int i = first+1; i < last+1; i++) {
    myCopy(&(array[i]), &key);
    j= i-1;
    while ((myCompare(key,array[j]) < 0) && myCompare(j,0) >= 0){
      myCopy(&(array[j]), &(array[j+1]));
      j = j-1;
    }
    myCopy(&key, &(array[j+1]));
  }              
    
}
