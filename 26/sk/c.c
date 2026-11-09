#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool ecvValid(char vstup[7]) {
    if(!((isalpha(vstup[0]) && isupper(vstup[0])) && (isalpha(toupper(vstup[1])) && isupper(vstup[1])))) {
        return false;
    }
    if(!(isdigit(vstup[2]) && isdigit(vstup[3]) && isdigit(vstup[4]))) {
        return false;
    }
    if(!((isalpha(vstup[5]) && isupper(vstup[5])) && (isalpha(vstup[6]) && isupper(vstup[6])))) {
        return false;
    }

    return true;
}

int main(void) {

    char vstup[50];
    scanf("%s", vstup);
    if(strlen(vstup) != 7) {
        printf("Nie\n");
        return 0;
    }

    printf("%s\n", ecvValid(vstup)? "Ano":"Nie");

    return 0;
}