#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    int n;
    scanf("%d", &n);

    char* logRetazec = (char *) malloc((n + 1) * sizeof(char));

    scanf("%s", logRetazec);
    
    int q;
    scanf("%d", &q);
    
    char** dvojice = (char **) malloc(q * sizeof(char *));
    int* res = (int *) calloc(q, sizeof(int));

    for(int i = 0; i < q; i++) {
        dvojice[i] = (char *) malloc(3 * sizeof(char));
        scanf("%2s", dvojice[i]);
    }

    for(int i = 0; i < q; i++) {
        char* p = logRetazec;
        while(p < logRetazec + strlen(logRetazec)) {
            if(strstr(p, dvojice[i]) != NULL) {
                res[i]++;
                p = strstr(p, dvojice[i]);
            }
            p++;
        }
        
        printf("%d\n", res[i]);
    }


    for(int i = 0; i < q; i++) {
        free(dvojice[i]);
    }
    free(dvojice);
    
    free(res);
    return 0;
}