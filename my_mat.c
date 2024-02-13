#include "my_mat.h"
#include <stdio.h>

void enterNum(int matrix[10][10]) {


    for(int i=0; i<10; i++) {
        for (int j=0; j<10; j++)
        {
            int num = 0;
            scanf("%d", &num);
            matrix[i][j] = num;        
        }
    }
}

void isPathHelpRec(int matrix[10][10], int i, int j, int visited[10], int *found) {

if(i==j) {
    *found = 0;
    return;    
}

visited[i] = 0;

for(int v=0;v<10;v++) {
    if(matrix[i][v]!=0 && visited[v]!=0) {
        isPathHelpRec(matrix, v, j, visited, found);
    }
}


}

int isPath(int matrix[10][10], int i, int j) {
    
   int visited[10];
   for(int o=0;o<10;o++) {
    visited[o] = 1;
   }
   int found = 1;
    if(i!=j) {
   isPathHelpRec(matrix, i, j, visited, &found);
    }
    
    return found;
}

int thePath(int matrix[10][10], int i, int j) {
    
    if(isPath(matrix, i, j)==1) {return -1;}

    int ans[10][10];

    for (int z=0; z<10; z++)
    {
        for (int t=0; t<10; t++)
        {
            ans[z][t] = matrix[z][t];
        }
    }

    for(int k=0; k<10; k++) {
        for(int z=0; z<10; z++) {
            for(int f=0; f<10; f++) {
                if(ans[z][k]+ans[k][f]<ans[z][f]&&(ans[z][k]!=0||ans[k][f]!=0)) {
                    ans[z][f] = ans[z][k]+ans[k][f];
                }
            }
        }
    }

    return ans[i][j];
    
}