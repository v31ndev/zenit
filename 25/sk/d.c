#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* readDynamicStr() {
    int len = 1;

    char* buff = malloc(len * sizeof(char));    
    if(buff == NULL) return NULL;

    int c, i = 0;
    while((c = getchar()) != '\n' && c != EOF) {
        if(i + 1 >= len) {
            len *= 2;
            char* new_buff = (char *) realloc(buff, len * sizeof(char));
            if(new_buff == NULL) {
                free(buff);
                return NULL;
            }

            buff = new_buff;
        }

        buff[i] = (char) c;
        i++;
    }

    buff[i] = '\0';

    if(i == 0 && c == EOF) {
        free(buff);
        return NULL;
    }

    return buff;
}

int main(void) {

    char* vstup;
    char* kodSubStr = "\0";
    do {
        vstup = readDynamicStr();
    } while((kodSubStr = strstr(vstup, "kod: ")) == NULL);

    kodSubStr += 5;

    char* koniec = (strpbrk(kodSubStr, ". \n") != NULL? strpbrk(kodSubStr, ". \n"):kodSubStr + strlen(kodSubStr));
    char* kodStr = (char *) malloc(((koniec - kodSubStr) + 2) * sizeof(char));
    strncpy(kodStr, kodSubStr, (koniec - kodSubStr) + 1);
    kodStr[(koniec - kodSubStr) + 1] = '\0';

    printf("%s\n", kodStr);

    free(vstup);
    free(kodStr);
    return 0;
}