// TODO

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {

    int n;
    scanf("%d", &n);

    int* cisla = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &cisla[i]);
    }

    /*
    int res[4][2] = {
        {0, 0},
        {INT_MAX, INT_MAX},
        {0, 0},
        {INT_MAX, INT_MAX}
    };
    */

    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cisla[i] * cisla[j] > res[0][0] * res[0][1]) {
                res[0][0] = i;
                res[0][1] = j;
            }
            if(cisla[i] * cisla[j] < res[1][0] * res[1][1]) {
                res[1][0] = i;
                res[1][1] = j;
            }
            if(cisla[i] / cisla[j] > res[2][0] / res[2][1]) {
                res[2][0] = i;
                res[2][1] = j;
            }
            if(cisla[i] / cisla[j] < res[3][0] / res[3][1]) {
                res[3][0] = i;
                res[3][1] = j;
            }
        }
    }
    */

    int* dvaMin = (int *) malloc(2 * sizeof(int));
    int* dvaMax = (int *) malloc(2 * sizeof(int));

    for(int i = 0; i < n; i++) {
        if() {
            
        }
    }

    printf("%d %d", );
    printf("%d %d", );
    printf("%d %d", );
    printf("%d %d", );

    //free(cisla);
    return 0;
}