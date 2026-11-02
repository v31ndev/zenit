#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* readDynamicStr() {
    size_t len = 1;

    char* buff = malloc(len * sizeof(char));    
    if(buff == NULL) return NULL;

    int c, i = 0;
    while((c = getchar()) != '\n' && c != EOF) {
        if(i + 1 >= (int)len) {
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

void freeSplit(char** splittedStr, int count) {
    for(int i = 0; i < count; i++) {
        free(splittedStr[i]);
    }
    free(splittedStr);
}

// TODO: PRE ZEFETIVNENIE PREPISAT TAK, ZE SA POUZIJE REALLOC S O(n) -> VSETKO V JEDNOM CYKLE
char** splitStr(char *str, char sep, int *count) {
    *count = 0;
    if(str[0] == '\0') {
        return NULL;
    }

    char** res = NULL;

    int i = 0;
    char *start = str, *end = str + 1;

    while(start != NULL && *start != '\0') {

        end = (strchr(start, sep) != NULL? strchr(start, sep):(start + strlen(start)));
        int lenStr = (end - start);

        (*count)++;

        if(res != NULL) {
            char** tmpRes = (char **) realloc(res, (*count) * sizeof(char *));
            if(tmpRes == NULL) {
                freeSplit(res, *count);
                *count = 0;
                return NULL;
            }
            res = tmpRes;
        }
        else {
            res = (char **) malloc(*count * sizeof(char *));
        }

        res[i] = (char *) malloc((lenStr + 1) * sizeof(char));

        if(res[i] == NULL) {
            freeSplit(res, i);
            return NULL;
        }
        
        strncpy(res[i], start, lenStr);
        res[i][lenStr] = '\0';

        start = (*end != '\0')? (end + 1):end;

        i++;
    }

    return res;
}

int containsN(int* arr, int len, int x) {
    int res = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] == x) res++;
    }
    return res;
}

int main(void) {

    int k;
    scanf("%d\n", &k);

    char* in = readDynamicStr();
    int n;
    char** inSplit = splitStr(in, ' ', &n);
    free(in);

    int* priklady = (int *) malloc(n * sizeof(int));
    
    int outN = 0;
    int* out = (int *) malloc(outN * sizeof(int));

    for(int i = 0; i < n; i++) {
        priklady[i] = (int) strtol(inSplit[i], NULL, 10);

        if(containsN(out, outN, priklady[i]) < k) {
            outN++;
            int* tmpOut = (int *) realloc(out, outN * sizeof(int));
            if(tmpOut == NULL)  return -1;
            out = tmpOut;
            out[outN - 1] = priklady[i];
        }
    }

    freeSplit(inSplit, n);

    for(int i = 0; i < outN; i++) {
        printf("%d", out[i]);
        if(i != outN - 1) printf(" ");
    }
    putchar('\n');

    free(priklady);
    free(out);
    return 0;
}