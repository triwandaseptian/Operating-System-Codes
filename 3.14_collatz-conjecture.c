/*
 * Name         : Tri Wanda Septian
 * Chapter 3.14* Programming
 * ++++++++++++
 * 3.14*: The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:
 * n= n/2, 		if n is even
 * n= 3*n+1, 		if n is odd
 * The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. 
 * For example,if n=35, the sequence is: 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1.
 * 
 * Write a C program using the fork() system call that generates this sequence in the child process. 
 * The starting number will be provided from the command line. 
 * For example, if 8 is passed as a parameter on the command line, the child process will output 8, 4, 2, 1. 
 * Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. 
 * Have the parent invoke the wait() call to wait for the child process to complete before existing the program.
 * Perform necessary error checking to ensure that a positive integer is passed on the command line.
 * 
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Operating System\n");
    printf("Name : Tri Wanda Septian\n");

    int n=0;
    int k=0;

    pid_t pid;

    do
    {
        printf("Please enter a number greater than 0 to run the Collatz Conjecture : ");scanf("%d", &k);
    }while (k <= 0);

    pid = fork();

    if (pid == 0)
    {
        printf("Child is working...\n");
        printf("%d\n",k);
        while (k!=1)
        {
            if (k%2 == 0)
            {
                k = k/2;
            }
            else if (k%2 == 1)
            {
                k = 3*(k)+1;
            }

            printf("%d\n",k);
        }

        printf("Child process is done.\n");
    }
    else
    {
        printf("Parents is waiting on child process...\n");
        wait(NULL);
        printf("Parent process is done.\n");
    }
    return 0;
}
