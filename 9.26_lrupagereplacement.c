/*
 * Name     : Tri Wanda Septian
 * How to compile the source codes (Linux)
 * $gcc -o a.out a.c
 * 
 *  * 9.26*: Write a program that implements the FIFO, LRU, and optimal page-replacement algorithms presented in this chapter.
 * First, generate a random page-reference string where page numbers range from 0 to 9.
 * Apply the random page-reference string to each algorithm, and record the number of page faults incurred by each algorithm.
 * Implement the replacement algorithm so that the number of page frames can vary from 1 to 7. Assume that demand paging is used.
 */

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

int findLRU(int time_t[], int n){
    int i, minimum = time_t[0], pos = 0;

    for(i = 1; i < n; ++i){
        if(time_t[i] < minimum){
            minimum = time_t[i];
            pos = i;
        }
    }

    return pos;
}

int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time_t[10], flag1, flag2, i, j, pos, faults = 0;

    printf("\nName : Tri Wanda Septian\n");
    
    printf("\nLRU Page Replacement\n");
    printf("Enter number of pages: ");scanf("%d", &no_of_pages);
    printf("Random number of reference string: ");
    srand(time(NULL));

    for(i = 0; i < no_of_pages; ++i){
        pages[i] = rand() % 8;
        printf("%d ", pages[i]);
    }
    printf("\nEnter number of frames: ");scanf("%d", &no_of_frames);
    printf("\n");
    printf("Ref string\t   Page Frames\n");
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        printf("%d\t\t",pages[i]);
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                counter++;
                time_t[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time_t[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0){
            pos = findLRU(time_t, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time_t[pos] = counter;
        }

        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
