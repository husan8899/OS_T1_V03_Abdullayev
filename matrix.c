
#include <stdio.h>
#include <stdlib.h>

int **matritsa_yarat(int n, int m) {
    int **a = malloc((size_t)n * sizeof(int *));

    if (a == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        a[i] = malloc((size_t)m * sizeof(int));

        if (a[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(a[j]);
            }
            free(a);
            return NULL;
        }
    }

    return a;
}

void matritsa_boshat(int **a, int n) {
    if (a == NULL) {
        return;
    }

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }

    free(a);
}

void kirit(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%d][%d] = ", i, j);

            if (scanf("%d", &a[i][j]) != 1) {
                printf("Xato: butun son kiriting!\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void chiqar(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n, m;

    printf("Qatorlar soni N (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Xato: N 1 dan 100 gacha bo'lishi kerak.\n");
        return 1;
    }

    printf("Ustunlar soni M (1-100): ");
    if (scanf("%d", &m) != 1 || m < 1 || m > 100) {
        printf("Xato: M 1 dan 100 gacha bo'lishi kerak.\n");
        return 1;
    }

    int **a = matritsa_yarat(n, m);
    if (a == NULL) {
        printf("Xato: matritsa uchun xotira ajratilmadi.\n");
        return 1;
    }

    int **t = matritsa_yarat(m, n);
    if (t == NULL) {
        printf("Xato: transponirlangan matritsa uchun xotira ajratilmadi.\n");
        matritsa_boshat(a, n);
        return 1;
    }

    printf("Matritsa elementlarini kiriting:\n");
    kirit(a, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[j][i] = a[i][j];
        }
    }

    printf("\nAsl matritsa:\n");
    chiqar(a, n, m);

    printf("\nTransponirlangan matritsa:\n");
    chiqar(t, m, n);

    matritsa_boshat(a, n);
    matritsa_boshat(t, m);

    printf("\nXotira muvaffaqiyatli bo'shatildi.\n");
    return 0;
}
