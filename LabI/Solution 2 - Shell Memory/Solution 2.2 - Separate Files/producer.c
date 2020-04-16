//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

/*
Lab I - Fork (Solution 2.2 - Shell Memory)  [ NOT WORKING DUE TO SYSTEM CONFIGURATION BUT CODE IS CORRECT ]

In this C-Code, we are using the shell memory as a medium to share information between concurrent processes.
However, there is a configuration on the server/system that is currently
copying the shell memory for those processes. 
Meaning that the consumer and producer processes are not actually sharing the same shell memory 
but have their own separate copies.
Until this configuration is fixed, this code wont print anything but it's logically correct (can be used for final).

Note that the other two methods, textfile and shared memory, definitely work as it's not dependent on
the system shell
*/

/*
COMPILATION INSTRUCTION:

Run the following commands on the terminal:

export TURN=Producer
gcc -o consumer consumer.c
gcc -o producer producer.c
./producer & ./consumer

*/

/*
This is the producer code. It is supposed to generate the number to be printed by the consumer.
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 10; i++)
    {
        while (strcmp(getenv("TURN"),"Producer")!=0); //wait for Producer turn

        char buffer[2];
        sprintf(buffer,"%d",i);
        setenv("VALUE",buffer,1);   //Assigned current number to VALUE
        setenv("TURN","Consumer",1);    //Gives next turn to consumer

    }
}

