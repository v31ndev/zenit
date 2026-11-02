#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int j, e, p_j= 0, p_e = 0;
    scanf("%d %d\n", &j, &e);

    int n;
    scanf("%d", &n);

    int *cisla = malloc(n * sizeof(int));
    if (cisla == NULL)
        return 1;

    for(int i = 0; i < n; i++) {
        scanf("%d", &cisla[i]);
        if(cisla[i] == j && cisla[i] == e) {
            p_j++;
            p_e++;
            continue;
        }
        else if(cisla[i] == j) {
            p_j++;
        }
        else if(cisla[i] == e) {
            p_e++;
        }
    }
    
    if(p_j > p_e)
        printf("Jergus\n");
    else if(p_j < p_e)
        printf("Ema\n");
    else
        printf("remiza\n");

    return 0;
}