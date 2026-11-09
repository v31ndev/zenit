/*
*   // TODO: NOT WORKING (at all lol)
*/


#include <stdio.h>
#include <string.h>

int main(void) {

    char vstup[4][10 * 100 + 10];

    for(int i = 0; i < 4; i++) {
        scanf("%1009s", vstup[i]);
    }

    int counter = 0;
    char* pomPtr = &vstup[2][0];
    while((pomPtr = strchr(pomPtr + 1, '-')) != NULL) {
        if(!((*(pomPtr - 9) == '<' || *(pomPtr + 1) == '1') || (*(pomPtr + 9) == '>' || *(pomPtr - 1) == '1'))) counter++;
        
    }

    printf("%d\n", counter);
    
    return 0;
}