#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {

    int n;
    scanf("%d", &n);    

    int* vstupy = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &vstupy[i]);
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += vstupy[i];
    }

    for(int i = 0; i < n; i++) {
        printf("%d\n", sum - vstupy[i]);
    }
    
    free(vstupy);
    return 0;
}