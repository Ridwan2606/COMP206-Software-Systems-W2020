//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

/*
Lab I - Fork (Solution 1 - Shared Memory)
In this C-Code, we are using the shared memory as a medium to share information between forked processes.
*/

/*
COMPILATION INSTRUCTION:

Run the following commands on the terminal:

gcc -o sharedmem sharedmem.c
./sharedmem

*/

#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h> 
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct SharedMemory {   //This is the shared memory struct 
     char* turn; //Turn stores whether it's the producer's or consumer's turn
     int value; //Stores the current value iterate by the producer, to be passed to the consumer
};

void producer(struct SharedMemory * ptr){
    for (int counter = 1 ; counter <= 10; counter++)   
    {
        while (strcmp(ptr->turn,"Producer")!=0); //While it's not the producer's turn, wait 
        
        ptr->value=counter; // Set value field in the shared memory  
        ptr->turn= "Consumer";   // Set the next turn to the consumer's
    }
}

void consumer(struct SharedMemory * ptr){
    while (1){
        while (strcmp(ptr->turn,"Consumer")!=0); //While it's not the consumer's turn, wait 
        
        printf("%d ", ptr->value);
        if (ptr->value == 10 ) break; //leave loop if it's the last number
        ptr->turn = "Producer";  
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int shm_id;   // Id for the shared memory
    struct SharedMemory *shmPTR; // Point to the shared memory

    int x = 10;

    shm_id = shmget(IPC_PRIVATE, sizeof(struct SharedMemory), IPC_CREAT | 0666);    //creating shared memory 
    shmPTR = (struct SharedMemory *) shmat(shm_id, NULL, 0);    //attach the shared memory by making shmPTR point to it
    shmPTR->turn = "Producer";  //First turn goes to producer

    int pid = fork();   // Forks the process      
    // at this point, shmPTR points to the same shared memory for both processes

    switch (pid) {
        case -1:    //Something went wrong
                perror("Fork");
                exit(1);
        
        case 0:   
                // This is the child branch as fork return 0 to the children. 
                // We will arbitrarily consider the consumer to be the children
                consumer(shmPTR);   
                printf("Id: %d Children (Consumer) terminating...\n",pid);
                break; 
        default:    
                // This is the parent branch as fork return the children pid to the parent.
                // We will arbitrarily consider the producer to be the parent
                producer(shmPTR);  
                printf("Id: %d Parent (Producer) terminating...\n",pid);
    }
    return 0;
}

