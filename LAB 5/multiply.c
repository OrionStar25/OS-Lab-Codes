#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10
#define K 10
#define NUM_THREADS 10

int A[MATRIX_SIZE][MATRIX_SIZE],B[MATRIX_SIZE][MATRIX_SIZE],C[MATRIX_SIZE][MATRIX_SIZE];

//VERTICE OF MATRIX
struct v 
{
   int i; /* row */
   int j; /* column */
};


void fill_matrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      matrix[i][j] = rand() % 10 + 1;
    }
  }
  return;
}


void *runner(void *param); /* the thread */

int main(int argc, char *argv[]) {

   int i,j, count = 0;
   fill_matrix(A);
   fill_matrix(B);

   for(i = 0; i < MATRIX_SIZE; i++)
   {
      for(j = 0; j < MATRIX_SIZE; j++)
      {
         //Assign a row and column for each thread
         struct v *data = (struct v *) malloc(sizeof(struct v));
         data->i = i;
         data->j = j;

         /* Now create the thread passing it data as a parameter */
         pthread_t tid;       //Thread ID
         pthread_attr_t attr; //Set of thread attributes

         //Get the default attributes
         pthread_attr_init(&attr);

         //Create the thread
         pthread_create(&tid,&attr,runner,data); //THREAD CREATION

         //Make sure the parent waits for all thread to complete
         pthread_join(tid, NULL);
         count++;
      }
   }

   //Print out the resulting matrix
   for(i = 0; i < MATRIX_SIZE; i++) {
      for(j = 0; j < MATRIX_SIZE; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}

//The thread will begin control in this function
void *runner(void *param) {
   struct v *data = param; // the structure that holds our data
   int n, sum = 0; //the counter and sum

   //Row multiplied by column
   for(n = 0; n< K; n++){
      sum += A[data->i][n] * B[n][data->j];
   }
   //assign the sum to its coordinate
   C[data->i][data->j] = sum;

   //Exit the thread
   pthread_exit(0);
}
