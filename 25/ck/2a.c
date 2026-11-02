#include <stdio.h>

int main(void) {

    int telUsek;
    scanf("%d", &telUsek);

    printf("<O");
    for(int i = 0; i < telUsek; i++) {
        printf("=");
    }
    printf("-\n");
    
    return 0;
}