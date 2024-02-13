
#include <stdio.h>

#define WEIGHT 20
#define LENGTH 5

int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int table[LENGTH+1][WEIGHT+1];
  
    // Build table table[][] in bottom up manner
    for (i=0; i<=LENGTH; i++) {
        for (w=0; w<=WEIGHT; w++) {
            if (i==0 || w==0)
                table[i][w] = 0;
            else {
                if (weights[i-1]<=w) {
                    if(values[i-1]+table[i-1][w-weights[i-1]]>table[i-1][w]) {
                        table[i][w] = values[i-1]+table[i-1][w-weights[i-1]];
                    }
                    else {
                        table[i][w] = table[i-1][w];
                    }
                }
                else {
                    table[i][w] = table[i-1][w];
                }
            }
        }
    }
  
    // Find the items included in the knapsack
    int res = table[LENGTH][WEIGHT];
    w = WEIGHT;
    for (i=LENGTH; i>0 && res>0; i--) {
        if (res==table[i-1][w])
            continue;
        else {
            selected_bool[i-1] = 1;
            res = res-values[i-1];
            w = w-weights[i-1];
        }
    }

    return table[LENGTH][WEIGHT];
}

int main() {
    
    char items[] = {'A', 'B', 'C', 'D', 'E'};
    int values[LENGTH];
    int weights[LENGTH];
    int seleced_bool[LENGTH];
    int max_profit;
    int i;

    for(i=0; i<LENGTH; i++) {
        seleced_bool[i] = 0;
    }

    for(i=0; i<LENGTH; i++) {
        scanf("%d", &values[i]);
    }

    for(i=0; i<LENGTH; i++) {
        scanf("%d", &weights[i]);
    }

    max_profit = knapSack(weights, values, seleced_bool);

    printf("Maximum profit: %d\n", max_profit);

    printf("Items that give the maximum profit: [");
    for (i=0; i<LENGTH; i++)
    {
        if(seleced_bool[i] == 1) {
            printf("%c, ", items[i]);
        }
    }
    printf("\b\b]\n");

    return 0;
}