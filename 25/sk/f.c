#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

    char zasobnik[400000] = "\0";
    int zIndex = 0;
    char vstup[400000];

    bool platne = true;

    if(scanf("%s", vstup) != 1) {
        printf("nie\n");
        return 0;
    }

    for(int i = 0; vstup[i] != '\0'; i++) {
        if(vstup[i] == '{' || vstup[i] == '[' || vstup[i] == '(') {
            zasobnik[zIndex++] = vstup[i];
        }
        else if(vstup[i] == '}' || vstup[i] == ']' || vstup[i] == ')') {
            if(zIndex == 0) {
                platne = false; 
                break;
            }

            char vrchol = zasobnik[zIndex - 1];

            if(
                (vstup[i] == '}' && vrchol == '{') ||
                (vstup[i] == ']' && vrchol == '[') ||
                (vstup[i] == ')' && vrchol == '(')
            ) {
                zIndex--;
            }
            else {
                platne = false;
                break;
            }
        }
        else {
            platne = false;
            break;
        }
    }

    if(zIndex != 0) platne = false;

    printf("%s\n", platne? "ano":"nie");

    return 0;
}