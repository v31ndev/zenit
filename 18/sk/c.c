#include <stdio.h>
#include <string.h>

int main(void) {
    char samo[100005], emo[100005];
    
    scanf("%s", samo);
    scanf("%s", emo);
    
    int n = strlen(samo);
    int m = strlen(emo);

    int pos = 0;
    for(int i = 0; i < n; i++) {
        if(samo[i] == '*') {
            pos = i;
            break;
        }
    }

    int pref_len = pos;
    int suf_len = n - pos - 1;

    // prefix + suffix nesmie byť dlhší než t
    if(pref_len + suf_len > m) {
        printf("NIE\n");
        return 0;
    }

    // kontrola prefixu
    for(int i = 0; i < pos; i++) {
        if(samo[i] != emo[i]) {
            printf("NIE\n");
        }
    }
    
    // kontrola suffixu
    for(int i = 0; i < suf_len; i++) {
        if(samo[n - 1 - i] != emo[m - 1 - i]) {
            printf("NIE\n");
            return 0;
        }
    }
    
    printf("ANO\n");
    return 0;
}