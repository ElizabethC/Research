// Program to generate exponential random variables

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#define NUM_TIMES 1000000000

//Generate Random number 
double Random(){

    return (((double)rand())/RAND_MAX);
}
int Exponential(int mu){

    int val = (int)(-1.0)*mu*log(1-Random());

    return val;
}

int Uniform(int min, int max){

    return min + (max - min)*Random();
}

int Geometric_Random(double p){
    return (int)(log(1.0-Random())/(log(p)));
}

int Equilikely_Random(int min, int max) {

    double r = Random();
    return (int)(min + r*(max-min+1)); 
}

int main(int argc, char *argv[])
{
    unsigned long int i = 0; // Loop counter
    int mu = 500000U; // Exponential random variable
    FILE *file;
    double rate; // For Geometric_Random function parameter 

 
    file  = fopen("case4.txt","w");
    printf( "Working ...\n");
    
    if ( file == NULL) {
        printf("Error \n");
        return 1;
    }
    rate = (double)(rand()/(double)RAND_MAX );
    for (i; i <NUM_TIMES; ++i) {
        fprintf(file, "%d ",Geometric_Random(0.5));
    }
    fclose(file);
    printf("Done\n");
    return 0;

}
