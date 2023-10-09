#include "mySort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        myCopy(&arr[l + i],&L[i]);
    for (j = 0; j < n2; j++)
        myCopy(&arr[m + 1 + j],&R[j]);
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while((myCompare(i,n1) < 0) && (myCompare(j,n2) < 0)){
        if ((myCompare(L[i],R[j]) <= 0)){
            myCopy(&L[i],&arr[k]);
            i++;
        }
        else {
            myCopy(&R[j],&arr[k]);
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */

    while(myCompare(i,n1) <0){
        myCopy(&L[i],&arr[k]);
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while(myCompare(j,n2) <0){
        myCopy(&R[j],&arr[k]);
        j++;
        k++;
    }
}
 
    

void mySort(int array[], unsigned int first, unsigned int last){
    
    if (myCompare(first,last) < 0){  
        int mid = first+(last-first) / 2;  
        mySort(array, first, mid);  
        mySort(array, mid + 1, last);  
        merge(array, first, mid, last);  
    }  
}

