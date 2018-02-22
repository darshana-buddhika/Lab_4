#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 65535;

// initializing a matrix

double** init_rand_matrix(int dim) {
 
  double ** matrix = (double **) malloc(sizeof(double *) * dim);
  for (int i = 0; i < dim; i++) {
      matrix[i] = (double *) malloc(sizeof(double) * dim);
  }

    for (int i = 0; i < dim; i++) {
      for (int j = 0; j < dim; j++) {
          matrix[i][j] = rand() % MAX_VAL;
      }
  }
  
  return matrix;
}

void print_matrix(double ** matrix, int dim){
    for (int i = 0; i < dim ; i++){
        for (int j =0 ; j < dim ; j++){
           
            printf("%lf ",matrix[i][j]);
        }
        printf("\n");
    }
}

double ** multiply_matrix(double ** matA, double ** matB, int dim){
    double ** matrix = (double **) malloc(sizeof(double *) * dim);
    for (int i = 0; i < dim; i++) {
        matrix[i] = (double *) malloc(sizeof(double) * dim);
    }    


    clock_t t;
    t = clock();
    
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
             for (int k= 0; k < dim ; k++){
                matrix[i][j]  += matA[i][k]*matB[k][j];
            }   
        }
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("Multipication took %f seconds to execute \n", time_taken);

    return matrix;
}
//main method

int main(int argc,char* argv[]){
    
    int n;
    double ** matA;
    double ** matB;
    double ** matC;

    if (argc != 2){ // check for required user arguments
        printf("Required arguments are not supplied\n");
        exit(1);
    } else {
        n = (int) strtol(argv[1], (char **)NULL, 10);  // assign metrix size from the user input
    }

    // random seed
    srandom(time(NULL));

    matA = init_rand_matrix(n);
    matB = init_rand_matrix(n);

    // printf("Matrix A\n");
    // print_matrix(matA, n);
    // printf("Matrix B\n");
    // print_matrix(matB, n);

    matC = multiply_matrix(matA, matB, n);

    // printf("matrix c\n");
    // print_matrix(matC, n);
}