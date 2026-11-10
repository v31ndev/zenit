/*
*   // TODO: 60% SUCCESS RATE
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int cisla[5];

    for(int i = 0; i < 5; i++) {
        scanf("%d", &cisla[i]);
    }

    int sum = 0;
    for(int i = 0; i < 5; i++) {
        if(cisla[i] > 0) sum += cisla[i];
    }
    
    printf("%d\n", sum);

    return 0;
}