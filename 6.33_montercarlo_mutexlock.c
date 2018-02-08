/*
 * Name     : Tri Wanda Septian
 * How to compile the source codes (Linux)
 * $gcc -pthread -o outputfile sourcecode.c
 * 
 * 6.33*: Exercise 4.17 asked you to design a multithreaded program that estimated pi using the Monte Carlo technique.
 * In that exercise, you were asked to create a single thread that generated random points, storing the result in a global variable.
 * Once that thread exited, the parent thread performed the calculation that estimated the value of pi.
 * Modify that program so that you create several threads, each of which generates random points and determines if the points fall within the circle. Each thread will have to update the global count of all points that fall within the circle. Protect against race conditions on updates to the shared global variable by using mutex locks.
 */

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>

int i = 0; //loop counter
int count = 0; //count holds all the number of how many good coordinates
double x,y; //x,y value for thre random coordinate
double z; //used to check if x*x+y*y <=1
long incircle = 0;
int totalpoints;


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *runner(void *param){
    /*initialize random numbers*/
    for (i= 0; i < totalpoints; ++i){

        x = (double)rand() / RAND_MAX; /*generate random x coordinate number*/
        y = (double)rand() / RAND_MAX; /*generate random y coordinate number*/

        z = x*x+y*y;
        if ( z <= 1){
            count++;
        }
    }
    pthread_mutex_lock(&mutex);
    incircle += count;
    pthread_mutex_unlock(&mutex);

}

int main(int argc, char *argv[]){

    printf("\nWelcome to Thread Process with Monte Carlo Technique(HW2) with Mutex lock\n");
    printf("\nName : Tri Wanda Septian\n");

    srand((unsigned int) time(NULL));

    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);


    if(argc !=2 ){
        fprintf(stderr,"\nUsage : mutex_lock.out <integer value>\n");
        return -1;
    }
    if (atoi(argv[1]) < 0){
        fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
        return -1;
    }

    int numberIter = atoi(argv[1]); //number if iterations per FOR LOPP
    totalpoints = numberIter;

    pthread_create(&thread,NULL,&runner, NULL); //create the thread
    pthread_join(thread,NULL);//wait forthre thread to exit

    pthread_mutex_destroy(&mutex);

    double phi = 4*((double)count/ (double) totalpoints); //phi calculation formula
    printf("\nNumber of trials = %d , estimate of phi is %g\n",totalpoints,phi);

    return 0;
}
