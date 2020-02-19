#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TA TEACHING INSTRUCTIONS

void printmatrix(int matrix[3][3]){

    for (int rowindex = 0; rowindex < 3; rowindex++)
    {
        for (int colindex = 0; colindex < 3; colindex++)
        {
            printf("%d ", matrix[rowindex][colindex]);
        }
        printf("\n");
    }  
}

int main(int argc, char const *argv[])
{
    int matrixA[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matrixB[3][3]={1,2,3,4,5,6,7,8,9};
    int result[3][3];
    
    for (int rowindex = 0; rowindex < 3; rowindex++)
    {
        for (int colindex = 0; colindex < 3; colindex++)
        {
            int sum = 0;
            for (int elementindex = 0; elementindex < 3; elementindex++)
            {
                sum+= matrixA[rowindex][elementindex]*matrixB[elementindex][colindex];
            }
            result[rowindex][colindex]=sum;
        }
        
    }
    
    printmatrix(result);
}


