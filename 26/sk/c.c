/*
*   // TODO: ONLY 60% SUCCESS RATE
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool ecvValid(char vstup[8]) {
    if(!(isalpha(toupper(vstup[0])) || isalpha(toupper(vstup[0])))) {
        return false;
    }
    if(!(isdigit(vstup[3]) || isdigit(vstup[4]) || isdigit(vstup[5]))) {
        return false;
    }
    if(!(isalpha(toupper(vstup[6])) || isalpha(toupper(vstup[7])))) {
        return false;
    }

    return true;
}

int main(void) {

    char vstup[50];
    scanf("%s", vstup);
    if(vstup[7] != '\0') {
        printf("Nie\n");
        return 0;
    }

    printf("%s\n", ecvValid(vstup)? "Ano":"Nie");

    return 0;
}