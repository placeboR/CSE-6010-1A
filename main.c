/*
 * main.c
 *
 *  Created on: 8/25/2018
 *      Author: Jingran He
 *
 * the purpose of the objects
 *  m - the number of matrix rows
 *  n - the number of matrix columns
 *  p - the possibility of a cell is written as '1'
 *  A - the original m*n matrix filled with random '1's and '0's
 *  tmp - temporary storing the modified m*n matrix according to the rules
 *  i - the counter for rows
 *  j - the counter for columns
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define m   5
#define n   5
#define p   0.1

int main(int argc, const char* argv[]){
    int A[m][n] = {0};	/* original matrix initialization */
    int tmp[m][n] = {0};	/* temporary storing the modified matrix initialization */
    
    int i,j = 0;	/* counters initialization */
    
    srand((unsigned)time(0));	/* set the starting point for producing pseudo-random integers */
    
    for(i = 0;i < m;i++){	/* scan for rows */
        for(j = 0;j < n;j++){	/* scan for columns */
            if(rand()%1000/(float)1001 <= p){    /* compare a random float number with p to control the possiblity of '1' */
                A[i][j] = 1;
            }
            else
                A[i][j] = 0;
        }
    }
    
    /* print the original matrix */
    printf("\n\nThe original matrix:\n\n");
    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++){
            printf("%d ",A[i][j]);  /* place a single space between '0's and '1's to enhance readability */
        }
        printf("\n");
    }
    
    /* calculate the modified matrix */
    int cnt = 0; /* the counter for the row or column contains '1' */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                for (cnt = 0; cnt < m; cnt++) {
                    tmp[cnt][j] = 1;  /* if there is a '1' in any cell of column j, all cells in the entire column should be set to 1 */
                }
                for (cnt = 0; cnt < n; cnt++) {
                    tmp[i][cnt] = 1;  /* if there is a '1' in any cell of row i, all cells in the entire row should be set to 1 */
                }
            }
        }
    }
    
    /* print the resulting matrix */
    printf("\n\nThe resulting matrix:\n\n");
    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++){
            A[i][j] = tmp[i][j];    /* update the original matrix */
            printf("%d ",A[i][j]);  /* place a single space between '0's and '1's to enhance readability */
        }
        printf("\n");
    }
    
    return 0;
}

