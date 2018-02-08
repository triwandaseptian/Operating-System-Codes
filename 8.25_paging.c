/*
 * Name     : Tri Wanda Septian
 * How to compile the source codes (Linux)
 * $gcc -o a.out a.c
 */

/*
 * Assume that a system has a 32-bit virtual address with a 4-KB page size.
 * Write a C program that is passed a virtual address (in decimal) on the command line and have it output the page number and offset for the given address.
 * As an example, your program would run as follows:
 * ./a.out 19986
 * Your program would output:
 * The address 19986 contains:
 * page number=4
 * offset=3602
 * Writing this program will require using the appropriate data type to store 32 bits. We encourage you to use unsigned data types as well.
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned long page;/*define page variable*/
    unsigned long offset;/*define offset variable*/
    unsigned long address;/*define address variable for input*/

    printf("\nName : Tri Wanda Septian\n");

    if(argc !=2 ){
        fprintf(stderr,"\nUsage : a.out <value>\n");
        fprintf(stderr,"Example : ./a.out 19986\n");
        return -1;
    }
    if (atoi(argv[1]) < 0){
        fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
        return -1;
    }

    address= atoi(argv[1]); /*address from variable from input*/

    page = address >> 12; /* Since page size is 4KB => 12 bits holding the virtual address*/
    offset = address & 0xfff;

    printf("\nThe address %lu contains: \n", address);
    printf("page number = %lu\n",page);
    printf("offset = %lu\n", offset);


    return 0;
}
