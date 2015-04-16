#include<stdio.h>
#include <stdlib.h> 

#define SIZE  1000000000

int Interpolation( int *array, int left, int right, int target){

    int low = 0;
    int count = 0;
    int mid;

    //As long as left is less than right
    while ( !(array[right]==array[left] || target < array[left]    ||
                array[right] < target)){

        mid = left + ( target - array[left]) * ((right - left)/ ( array[right]- array[left] ));

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
    if ( target == array[left]){
        return left;
    }
    else{
        return -1;
    }
}

int main(int argc, char**argv){

    int target;
    int left =0;
    int right = SIZE;
    FILE * fp;
    int array[SIZE];
    int arraysize;
    int i;
 
    if( argc != 3 ){
        printf("Syntax <search value> <file name> <arraysize>");
        exit(-1);
    }
   //Parse command line arguments
    target = atoi(argv[0]);
    arraysize = atoi(argv[2]);
   

    fp = fopen(argv[1], "r");
    if ( fp == NULL){
        fprintf(stderr, "Can't open input files!\n");
        exit(1);
    }
    while(!feof(fp)){
        for(i=0; i < SIZE; ++i){
            
            fscanf(fp,"%d",&array[i]);
        }
    }
    fclose(fp);    
    
    Interpolation(array, left, right, target);
    
    return 0;
}
