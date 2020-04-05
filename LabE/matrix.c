//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TA TEACHING INSTRUCTIONS

/*
This function prints the content of a 3x3 matrix passed as a 2D array.
*/
void printmatrix(int matrix[3][3]){

    // for each row
    for (int rowindex = 0; rowindex < 3; rowindex++)
    {
        // for each column of that row
        for (int colindex = 0; colindex < 3; colindex++)
        {
            // print the entry
            printf("%d ", matrix[rowindex][colindex]);
        }

        // Go to a fresh line after a row is completed
        printf("\n");
    }  
}

int main(int argc, char const *argv[])
{
    // Note the 2 ways to assign the same (content-wise, not pointer-wise) 2D array
    // to the 2 variables: matrixA, matrixB
    int matrixA[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matrixB[3][3]={1,2,3,4,5,6,7,8,9};
    int result[3][3];
    
    // To understand the algorithm, it would be advisable to first have a refresher on 
    // matrix multiplication from your linear algebra classes.

    // At the (rowindex)th row in the result matrix
    for (int rowindex = 0; rowindex < 3; rowindex++)
    {
        // At the (colindex)th column of that row in the result matrix
        for (int colindex = 0; colindex < 3; colindex++)
        {
            // Perform the dot product between the
            // (rowindex)th row of matrixA and (colindex)th column of matrixB
            int sum = 0;
            for (int elementindex = 0; elementindex < 3; elementindex++)
            {
                sum+= matrixA[rowindex][elementindex]*matrixB[elementindex][colindex];
            }
            result[rowindex][colindex]=sum;
        }
        
    }
    
    //prints the matrix
    printmatrix(result);
}


