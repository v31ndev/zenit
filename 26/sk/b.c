#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {

    if(*(int*)a > *(int*)b) {
        return 1;
    }
    if(*(int*)a < *(int*)b) {
        return -1;
    }
    return 0;
}

int main(void) {

    int n;
    scanf("%d", &n);

    int* cisla = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &cisla[i]);
    }

    qsort(cisla, n, sizeof(cisla[0]), comp);

    if(n > 1) {
        printf("%d %d\n", cisla[n - 1], cisla[n - 2]);
    }
    else {
        printf("%d\n", cisla[n - 1]);
    }

    free(cisla);
    return 0;
}