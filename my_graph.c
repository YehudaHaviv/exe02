
#include "my_mat.h"
#include <stdio.h>

int main() {
    
    char input;
    int matrix[10][10];

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            matrix[i][j] = 0;
        }
    }
    
    scanf(" %c", &input);
    while (input!='D' && input!=EOF)
    {   
        
        if (input=='A')
        {
            enterNum(matrix);
        }

        if (input=='B')
        {
            int i = 0;
            int j = 0;
            scanf("%d", &i);
            scanf("%d", &j);
            int ans = isPath(matrix, i, j);
            if(ans==1) {printf("False\n");}
            else {printf("True\n");}
        }

        if (input=='C')
        {
            int i = 0;
            int j = 0;
            scanf("%d", &i);
            scanf("%d", &j);
            int num = thePath(matrix, i, j);
            printf("%d\n", num);
        }
        
        scanf("%c", &input);
    }
    
    return 0;
}