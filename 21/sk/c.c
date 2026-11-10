/*
*   //TODO: SYNTACTICALLY CORRECT, BUT NOT ACCEPTED BY THE JUDGEMENT MACHINE
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fig(int n, int p) {
    n = abs(n);

    for(int i = 0; i < p; i++) {
        n /= 10;
    }

    return n % 10;
}

int main(void) {

    int n;
    scanf("%d", &n);

    int* vstupy = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &vstupy[i]);
    }

    for(int i = 0; i < n; i++) {
        int k = INT_MAX;
        int figureCount = floor(log10(abs(vstupy[i]))) + 1;


        for(int j = 0; j < figureCount; j++) {
            if(fig(vstupy[i], j) < k)   k = fig(vstupy[i], j);
        }
        
        printf("%d\n", k);
    }
    
    free(vstupy);
    return 0;
}