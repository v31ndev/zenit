#include <stdio.h>

int main(void) {

    int a, b, x;

    scanf("%d %d %d", &a, &b, &x);

    if(((a ^ x) & (a ^ b)) == (a ^ x)) {
        printf("ano\n");
    }
    else {
        printf("nie\n");
    }
    
    return 0;
}