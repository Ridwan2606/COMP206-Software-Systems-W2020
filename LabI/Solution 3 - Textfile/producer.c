//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

/*
Lab I - Fork (Solution 3 - Textfile)

In this C-Code, we are using a textfile (shared.txt) as a medium to share information 
between concurrent processes.
*/

/*
COMPILATION INSTRUCTION:

Run the following commands on the terminal:

gcc -o consumer consumer.c
gcc -o producer producer.c
./producer & ./consumer

*/

/*
This is the producer code. It is supposed to generate the number to be printed by the consumer.
*/
#include<stdio.h>
#include<stdlib.h>


int main() {

    //pointer to the shared file
    FILE *fp;

    // for each number
    for (int i = 1; i <= 10; i++){

        // busy wait until file can be opened
        while ((fp=fopen("shared.txt","a")) == NULL);
        
        // append current number in the file
        fprintf(fp,"%d ", i);

        // close the file
        fclose(fp);
    }

    // busy wait until file can be opened
    while ((fp=fopen("shared.txt","a")) == NULL);
    // append "OVER" in the file to indicate to the consumer that transmission of data is over
    fprintf(fp,"OVER");
    // close the file
    fclose(fp);

    return 0;
}