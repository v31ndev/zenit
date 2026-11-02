#include <stdio.h>
#include <math.h>

int main(void) {
    /* 
        n -> počet dní, ktoré máme na vybavenie objednávky
        m -> počet baktérií, ktoré potrebujeme
        k -> koeficient množenia baktérií
    */
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    if(!(n >= 1 && n <= (int)pow(10, 3)))
        return 0;
    if(!(m >= 1 && m <= (int)pow(10, 18)))
        return 0;
    if(!(k >= 1 && k <= (int)pow(10, 9)))
        return 0;

    if(m >= (int)pow(k, n)) {
        printf("-1\n");
        return 0;
    }

    int p_bak = 0;

    for(int i = 0; i < n; i++) {
        p_bak *= k;

        printf("%d ");
    }

    printf("\n");
    
    return 0;
}