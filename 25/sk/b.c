#include <stdio.h>

int main(void) {
    
    int sum = 0;
    for(int i = 0; i < 7; i++) {
        int cislo;
        scanf("%d", &cislo);
        sum += cislo;
    }
    printf("%d\n", sum + 1);
    
    return 0;
}