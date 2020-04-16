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
This is the consumer code. It is supposed to print the number generated by the producer.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1

int main(int argc, char* argv[]) {
    // pointer to the shared file
    FILE *fp; 
    // buffer to read line from file
    char buffer[100]; 
    // position of number to access (number of spaces before that number)
    int no_values = 0; 
    while (TRUE) {
        
        // busy wait until file can be opened
        while (((fp=fopen("shared.txt", "rt")) == NULL));  
        
        // Get first line and close file.
        fgets(buffer,99,fp);
        fclose(fp); 


        //skip no_values number of spaces to get to the desired number
        // same e.g buffer="1 2 3 4 5 6 7 8" , no_values = 3
        // That means that we want the 4th number
        // At this point, token = "4" & buffer= "5 6 7 8"
        char* token = strtok(buffer, " ");
        int tokenNum = 0;
        while( tokenNum<no_values) {
            token = strtok(NULL, " ");
            tokenNum++;
        }

        // If producer signaled that it's end of the transmission, End
        if (strcmp(token,"OVER")==0){
            break;
        // Else print the number
        } else {
            printf("%s ", token);
        }
        // We want the next number now
        no_values++;
    } 

    //prints new line
    printf("\n"); 
    //Delete the shared file.
    system("rm shared.txt"); 
}

