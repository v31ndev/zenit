#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char meno[41];
    long long dlh;
} pribuzny;

// Porovnanie podľa mena (lexikograficky)
int cmp_meno(const void *a, const void *b) {
    return strcmp(((pribuzny*)a)->meno, ((pribuzny*)b)->meno);
}

// Porovnanie dlhov zostupne
int cmp_dlh_desc(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return 1;
    else if (x > y) return -1;
    else return 0;
}

int main(void) {
    int n, k;
    // n -> pocet pribuznych
    scanf("%d %d", &n, &k);

    pribuzny *pribuzni = (pribuzny*)malloc(n * sizeof(pribuzny));
    for(int i = 0; i < n; i++) {
        scanf("%s %lld", pribuzni[i].meno, &pribuzni[i].dlh);
    }

    // Zoradíme podľa mena, aby sme mohli spojiť dlhy rovnakého príbuzného
    qsort(pribuzni, n, sizeof(pribuzny), cmp_meno);
    long long *merged_debts = (long long*)malloc(n * sizeof(long long));
    int u = 0; // počet unikátnych mien

    for (int i = 0; i < n; ) {
        long long sum = pribuzni[i].dlh;
        int j = i + 1;
        while (j < n && strcmp(pribuzni[i].meno, pribuzni[j].meno) == 0) {
            sum += pribuzni[j].dlh;
            j++;
        }
        merged_debts[u++] = sum;
        i = j;
    }

    // Zoradíme dlhy zostupne
    qsort(merged_debts, u, sizeof(long long), cmp_dlh_desc);

    // Spočítame k najväčších
    long long result = 0;
    int take = (k < u ? k : u);
    for (int i = 0; i < take; i++) {
        result += merged_debts[i];
    }

    printf("%lld\n", result);

    free(pribuzni);
    free(merged_debts);

    return 0;
}