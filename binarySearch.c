#include<stdio.h>
#include <stdlib.h> 

#define SIZE  1000000000
int BinarySearch( int *array, int left, int right, int target){

    int low = 0;
    int count = 0;
    int mid;

    //As long as left is less than right
    while ( left <= right){

        mid = left + ( right - left ) / 2;

        //if the search key on the left half
        if (target < array[mid]){

            right = mid -1;
        }
        //If the search key on the right half
        else if ( target > array[mid]){

            left = mid +1;
        }
        else{
            count++;
            printf("Found it! Total elements are %d\n", count);
            return mid;
        }
    }
    // key was not found 
    return -1;
}

int main(int argc, char *argv[])
{

    int target;
    FILE * fp;
    int *array;
    int arraysize;
    int i;
    int left =0;
    int right = arraysize;
 
    if( argc != 4 ){
        printf("Syntax <search value> <file name> <arraysize>\n");
        exit(-1);
    }
   //Parse command line arguments
    target = atoi(argv[1]);
    arraysize = atoi(argv[3]);
    array = calloc(sizeof(int), arraysize);
   

    fp = fopen(argv[2], "r");
    if ( fp == NULL){
        fprintf(stderr, "Can't open input files!\n");
        exit(1);
    }
    for(i=0; i < arraysize && !feof(fp); ++i){
            fscanf(fp,"%d",&array[i]);
    }
    fclose(fp);    
    
    BinarySearch(array, left, right, target);
    
    return 0;
}
