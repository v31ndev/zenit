#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int* kopce = malloc(n * sizeof(int));
    
    int pDelNula = 0, pDelJedna = 0, pDelDva = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &kopce[i]);

        switch(kopce[i] % 3) {
            case 0: {
                pDelNula++;
                break;
            }
            case 1: {
                pDelJedna++;
                break;
            }
            case 2: {
                pDelDva++;
                break;
            }
        }
    }

    int iDelNula = 0, iDelJedna = 0, iDelDva = 0;
    int** podlaDelitelnosti = (int **) malloc(3 * sizeof(int *));
    podlaDelitelnosti[0] = (int *) malloc(pDelNula * sizeof(int));
    podlaDelitelnosti[1] = (int *) malloc(pDelJedna * sizeof(int));
    podlaDelitelnosti[2] = (int *) malloc(pDelDva * sizeof(int));

    for(int i = 0; i < n; i++) {
        switch(kopce[i] % 3) {
            case 0: {
                podlaDelitelnosti[0][iDelNula++] = kopce[i];
                break;
            }
            case 1: {
                podlaDelitelnosti[1][iDelJedna++] = kopce[i];
                break;
            }
            case 2: {
                podlaDelitelnosti[2][iDelDva++] = kopce[i];
                break;
            }
        }
    }

    if(pDelNula >= 3) {
        printf("%d %d %d\n", podlaDelitelnosti[0][0], podlaDelitelnosti[0][1], podlaDelitelnosti[0][2]);
    }
    else if(pDelJedna >= 3) {
        printf("%d %d %d\n", podlaDelitelnosti[1][0], podlaDelitelnosti[1][1], podlaDelitelnosti[1][2]);
    }
    else if(pDelDva >= 3) {
        printf("%d %d %d\n", podlaDelitelnosti[2][0], podlaDelitelnosti[2][1], podlaDelitelnosti[2][2]);
    }
    else if(pDelNula >= 1 && pDelJedna >= 1 && pDelDva >= 1) {
        printf("%d %d %d\n", podlaDelitelnosti[0][0], podlaDelitelnosti[1][0], podlaDelitelnosti[2][0]);
    }

    free(kopce);
    for(int i = 0; i < 3; i++)
        free(podlaDelitelnosti[i]);
    free(podlaDelitelnosti);
    return 0;
}