#include<stdio.h> //main header file
#include<pthread.h> //pthread lib for c
#include<unistd.h> //for sleep()

void *thread_fn(void *arg)
{
  	long id =(long) arg;
  	printf("Starting thread %ld\n", id);
  	sleep(5);
  	printf("Exiting thread %ld\n", id);
  	return NULL;
}

int main()
{
 	pthread_t t1,t2; //2 threads 
 
 	pthread_create(&t1,NULL,thread_fn,(void *)1); //creating thread
 	pthread_create(&t2,NULL,thread_fn,(void *)2); //creating thread
 	pthread_join(t1,NULL);  //waits for t1 to terminate
	pthread_join(t2,NULL);  //waits for t2 to terminate
 	printf("Exiting main\n");
 	return 0;
}

