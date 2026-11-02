#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int* cisla = malloc(n * sizeof(int));
    int sum = 0;


    for(int i = 0; i < n; i++) {
        scanf("%d", &cisla[i]);
        sum += cisla[i];
    }

    printf("%d", sum);
    free(cisla);
    
    return 0;
}