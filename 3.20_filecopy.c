/*
 * Name         : Tri Wanda Septian
 * 
 * Chapter 3.20*
 * 3.20*: Design a file-copying program named filecopy using ordinary pipes. 
 * This program will be passed two parameters: the name of the file to be copied and the name of the copied file. 
 * The program will then create an ordinary pipe and write the contents of the file to be copied to the pipe. 
 * The child process will read this file from the pipe and write it to the destination file. 
 * For example, if we invoke the program as follows:
 * 
 * filecopy input.txt copy.txt
 * 
 * the file input.txt will be written to the pipe. The child process will read the contents of this file and write it to the destination file copy.txt.
 * You may write this program using either UNIX or Windows pipes.
 * 
 */
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>

int main( int argc, char* argv[]) {
    int fdone[2];
    pid_t childId;

    char readBuff[50];
    char writeBuff[50];

    int readCounter;

    pipe(fdone);

    if(argc < 3){
        printf("Operating System Homework 1\n");
        
        printf("Filecopy Program\n");
        printf("At least need 2 params");
        exit(1);
    }

    int fileOpen = open( argv[1],0);
    int targetFile = open(argv[2],0666);

    if (fileOpen == -1 || targetFile ==  -1 ){
        printf("Opening file Failed!!!");
        exit(1);
    }
    childId = fork();

    if(childId == 0){
        //inside the child process
        close(fdone[1]);

        read(fdone[0], readBuff,sizeof(readBuff));
        printf("The received string is : %s", readBuff);

        //Writing to the target fileOpen
        write(targetFile, readBuff,strlen(readBuff)+1);
    }else{
        //inside the parent process
        close(fdone[0]);

        //code to read from a text file
        while((readCounter = read(fileOpen,readBuff,sizeof(readBuff))>0)){
            write(fdone[1], readBuff, sizeof(readBuff));
        }
        close(fdone[1]);
    }
}
