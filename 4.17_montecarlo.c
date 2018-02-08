/*
 * Name     : Tri Wanda Septian
 * 
 * How to compile the source codes (Linux)
 * $gcc -pthread -o outputfile sourcecode.c
 * 
 * 4.17*: An interesting way of calculating phi is to use a technique known as Monte Carlo, which involves randomization. 
 * This technique works as follows: Suppose you have a circle inscribed within a square, as shown in Figure 4.18. 
 * (Assume that the radius of this circle is 1.)
 * 
 * First, generate a series of random points as simple (x,y) coordinates. These points must fall within the Cartesian coordinates that bound the square. Of the total number of random points that are generated, some will occur within the circle.
 * Next, estimate phi by performing the following calculation:
 * phi =4*(number of points in circle)/(total number of points)
 * Write a multithreaded version of this algorithm that creates a separate thread to generate a number of random points.
 * The thread will count the number of points that occur within the circle and store the result in a global variable.
 * When this thread has exited, the parent thread will calculate and output the estimated value of phi. 
 */

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>

int i = 0; //loop counter
int count = 0; //count holds all the number of how many good coordinates
double x,y; //x,y value for thre random coordinate
double z; //used to check if x*x+y*y <=1
int totalpoints;

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
    pthread_exit(0);
}

int main(int argc, char *argv[]){

    printf("\nWelcome to Thread Process with Monte Carlo Technique\n");

    srand((unsigned int) time(NULL));
    pthread_t thread; // the thread identifier


    if(argc !=2 ){
        fprintf(stderr,"\nUsage : montecarlo.out <integer value>\n");
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

    double phi = 4*((double)count/(double)totalpoints); //phi calculation formula
    printf("\nNumber of Iteration = %d , estimate of phi is %g \n",totalpoints,phi);

    return 0;

}
