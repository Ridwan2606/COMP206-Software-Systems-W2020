//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

/*
Lab I - Fork (Solution 2.1 - Shell Memory)  [ NOT WORKING DUE TO SYSTEM CONFIGURATION BUT CODE IS CORRECT ]

In this C-Code, we are using the shell memory as a medium to share information between forked processes.
However, there is a configuration on the server/system that is currently
copying the shell memory for the forked processes. 
Meaning that the children and parent are not actually sharing the same shell memory 
but have their own separate copies
Until this configuration is fixed, this code wont print anything but it's logically correct 
(can be used for final).

Note that the other two methods, textfile and shared memory, definitely work as it's not dependent on
the system shell
*/

/*
COMPILATION INSTRUCTION:

Run the following commands on the terminal:

gcc -o shellmem shellmem.c
./shellmem

*/

#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h> 
#include <string.h>

void consumer(){
    int value;
    do
    {
        while (strcmp(getenv("TURN"),"Consumer")!=0); //wait for Consumer turn   

        value = atoi(getenv("VALUE"));  
        printf("%d ",value);    //Prints the value 
        setenv("TURN","Producer",1);    //Gives next turn to producer 

    } while (value!=10); //repeat until last number is reached 
}

void producer(){
    for (int i = 1; i <= 10; i++) 
    {
        while (strcmp(getenv("TURN"),"Producer")!=0); //wait for Producer turn   
        
        char buffer[2];
        sprintf(buffer,"%d",i);  
        setenv("VALUE",buffer,1);   //Assigned current number to VALUE
        setenv("TURN","Consumer",1);    //Gives next turn to consumer

    }
}

int main(int argc, char const *argv[])
{
    int pid;
    setenv("TURN","Producer",1); //First turn goes to Producer
    pid = fork();   // Forks the process       
    
    switch (pid) {
        case -1:    //Something went wrong
                perror("Fork");
                exit(1);
        
        case 0:   
                // This is the child branch as fork return 0 to the children. 
                // We will arbitrarily consider the consumer to be the children
                consumer();
                printf("Id: %d Children (Consumer) terminating...\n",pid);
                break;
        default:    
                // This is the parent branch as fork return the children pid to the parent.
                // We will arbitrarily consider the producer to be the parent
                producer();   
                printf("Id: %d Parent (Producer) terminating...\n",pid);             

    }
    return 0;
}

