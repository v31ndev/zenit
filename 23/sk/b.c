#include <stdio.h>
#include <string.h>

int main(void) {

    char vstup [100000 * 2 + 11];

    scanf("%s", vstup);

    char* pPtr = strchr(vstup, '-');
    *pPtr = '\0';

    int counter = 0;
    char* iPtr = vstup;
    while((iPtr = strstr(iPtr, "ne")) != NULL) {
        counter++;
        iPtr++;
    }

    printf("%s\n", counter % 2 == 0? "ano":"nie");
    
    return 0;
}