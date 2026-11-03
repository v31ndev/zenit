/*
* // TODO: oPtImIzE
* for some reason it has 50% of correct answers, because:
*   1. apparently 5x10 is different than 10x5
*   2. for half of the test sets my program is a quarter slower than it should be
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int comp(const void* a, const void* b) {
    if(*(long*)a > *(long*)b) {
        return 1;
    }
    if(*(long*)a < *(long*)b) {
        return -1;
    }
    return 0;
}

int main(void) {

    int n;
    scanf("%d", &n);

    long* cisla = (long*) malloc(n * sizeof(long));

    for(int i = 0; i < n; i++) {
        scanf("%ld", &cisla[i]);
    }

    qsort(cisla, n, sizeof(cisla[0]), comp);

    long int res[4][2] = {
        {cisla[0], cisla[1]},
        {cisla[0], cisla[1]},
        {cisla[0], cisla[1]},
        {cisla[0], cisla[1]}
    };

    long int* pom1 = &cisla[0], *pom2 = &cisla[1];
    while(pom1 <= &cisla[n - 1]) {
        while(pom2 <= &cisla[n - 1]) {
            if((*pom1) * (*pom2) > res[0][0] * res[0][1]) {
                res[0][0] = *pom1;
                res[0][1] = *pom2;
            }

            if((*pom1) * (*pom2) < res[1][0] * res[1][1]) {
                res[1][0] = *pom1;
                res[1][1] = *pom2;
            }

            if((double)(*pom1) / (*pom2) > (double)res[2][0] / res[2][1]) {
                res[2][0] = *pom1;
                res[2][1] = *pom2;
            }
            else if((double)(*pom2) / (*pom1) > (double)res[2][0] / res[2][1]) {
                res[2][0] = *pom2;
                res[2][1] = *pom1;
            }

            if((double)(*pom1) / (*pom2) < (double)res[3][0] / res[3][1]) {
                res[3][0] = *pom1;
                res[3][1] = *pom2;
            }
            else if((double)(*pom2) / (*pom1) < (double)res[3][0] / res[3][1]) {
                res[3][0] = *pom2;
                res[3][1] = *pom1;
            }
            pom2++;
        }
        pom1++;
        pom2 = pom1 + 1;
    }

    for(int i = 0; i < 4; i++) {
        printf("%ld %ld\n", res[i][0], res[i][1]);
    }

    free(cisla);
    return 0;
}