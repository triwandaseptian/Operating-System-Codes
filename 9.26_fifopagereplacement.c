/*
 * Name     : Tri Wanda Septian
 *
 * How to compile the source codes (Linux)
 * $gcc -o a.out a.c
 * 
 * 9.26*: Write a program that implements the FIFO, LRU, and optimal page-replacement algorithms presented in this chapter.
 * First, generate a random page-reference string where page numbers range from 0 to 9.
 * Apply the random page-reference string to each algorithm, and record the number of page faults incurred by each algorithm.
 * Implement the replacement algorithm so that the number of page frames can vary from 1 to 7. Assume that demand paging is used.
 */
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,j,n,a[50],frame[10],no,k,avail,count=0;

    printf("\nName : Tri Wanda Septian\n");

    printf("\nFIFO Page Replacement\n");
    printf("\nEnter the number of page: ");scanf("%d",&n);
    printf("\nRandom number of the references string : ");

    srand(time(NULL));

    for(i=1;i<=n;i++) { //create the randomize numbers
        a[i] = rand() % 8;
        printf("%d ", a[i]);
    }
    printf("\nEnter the frames numbers : ");scanf("%d",&no);
    for(i=0;i<no;i++)
        frame[i]= -1;
    j=0;
    printf("\n");
    printf("ref string\t   page frames\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
            if(frame[k]==a[i])
                avail=1;
        if (avail==0)
        {
            frame[j]=a[i];
            j=(j+1)%no;
            count++;
            for(k=0;k<no;k++)
                printf("%d\t",frame[k]);
        }
        printf("\n");
    }

    printf("\nPage Fault Is %d\n",count);
    return 0;
}

