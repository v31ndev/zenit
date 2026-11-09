#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

    int n;
    scanf("%d", &n);
    
    char** vstup = (char **) malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++) {
        vstup[i] = (char *) malloc(51 * sizeof(char));
        scanf("%50s", vstup[i]);
    }

    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(strchr(vstup[i], '(') || strchr(vstup[i], ')')) {
            tmp = 0;
            if(strchr(vstup[i], '<') || strchr(vstup[i], '>')) {
                tmp = 1;
                return 0;
            }
        }
    }

    printf("%s\n", !tmp? "dazdovka":"had");

    for(int i = 0; i < n; i++) {
        free(vstup[i]);
    }
    free(vstup);
    return 0;
}