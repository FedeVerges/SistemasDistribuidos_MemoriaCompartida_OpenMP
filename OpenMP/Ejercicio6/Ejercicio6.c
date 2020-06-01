#include <stdio.h>
#include <omp.h>
int main(int argc, char **argv)
{
    omp_set_num_threads(3);
    int rows = 3;
    int columns = 3;
    int rows_b = columns;
    int columns_b = 3;

    int matrix_size = rows * columns;
    int matrix_a [rows][columns];
    int matrix_b [rows_b][columns_b]; // rows of b = columns of a.
    
    int result_matrix [rows][columns_b]; // a=3x3 and b=3x2 => result=3x2 (a-rows X b-columns).
    int index_row;
    int index_column;
    int index_column_b; // index for the matriz-b
    int temp = 0; // temporal value to add the multiply values of the matrix.

    // Inicialize matrix_a

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix_a[i][j]= i+j;
        }
    }

    // Inicialize matrix_b


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix_b[i][j]= i+j;
        }        
    }

    // Inicialize result_matrix

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result_matrix[i][j] = 0;
        } 
    }

    printf(" Matriz a \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d" ,matrix_a[i][j]);
        }
        printf("\n");
        
    }

    printf("\n Matriz b \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d" ,matrix_b[i][j]);
        }

        printf("\n");
        
    }

    printf("\n Matriz resultado: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns_b; j++)
        {
            printf("%d " ,result_matrix[i][j]);
        }

        printf("\n");
        
    }

#pragma omp parallel private(index_row,index_column,index_column_b, temp)
    {
        for (index_column_b = 0; index_column_b < columns_b; index_column_b++) // need to go over the row the matrix_b and result_matrix.
        {
            #pragma omp for
            for(index_row = 0; index_row<rows; index_row++){
                for(index_column = 0; index_column< columns; index_column++){
                    temp += matrix_a[index_row][index_column] * matrix_b[index_column][index_column_b]; // index_colum = rows_b.
                }
                result_matrix[index_row][index_column_b]= temp; // put the result on the result matrix.
                temp = 0; // reinicialice temp.
            }
    }

}
    printf("\n\n Resultado de la matriz : \n");
   for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns_b; j++)
        {
            printf(" %d " ,result_matrix[i][j]);
        }

        printf("\n");
        
    }

    return (0);
}