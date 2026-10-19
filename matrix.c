#include <stdio.h>
#include <stdlib.h>

int **yarat(int n, int m)
{
    int **a = malloc(n * sizeof(int *));

    if (a == NULL)
        return NULL;

    for (int i = 0; i < n; i++) {
        a[i] = malloc(m * sizeof(int));

        if (a[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(a[j]);

            free(a);
            return NULL;
        }
    }

    return a;
}

void chiqar(int **a, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }
}

void transponirlash(int **a, int **t, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            t[j][i] = a[i][j];
    }
}

void boshat(int **a, int n)
{
    if (a == NULL)
        return;

    for (int i = 0; i < n; i++)
        free(a[i]);

    free(a);
}

int main(void)
{
    int n, m;

    printf("Qator va ustun sonini kiriting (1-100): ");

    if (scanf("%d %d", &n, &m) != 2 ||
        n < 1 || n > 100 || m < 1 || m > 100) {
        printf("Xato: o'lchamlarni to'g'ri kiriting!\n");
        return 1;
    }

    int **a = yarat(n, m);

    if (a == NULL) {
        printf("Xotira ajratishda xatolik!\n");
        return 1;
    }

    int **t = yarat(m, n);

    if (t == NULL) {
        boshat(a, n);
        printf("Xotira ajratishda xatolik!\n");
        return 1;
    }

    printf("Matritsa elementlarini kiriting:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Xato: butun son kiriting!\n");
                boshat(a, n);
                boshat(t, m);
                return 1;
            }
        }
    }

    printf("\nAsl matritsa:\n");
    chiqar(a, n, m);

    transponirlash(a, t, n, m);

    printf("\nTransponirlangan matritsa:\n");
    chiqar(t, m, n);

    boshat(a, n);
    boshat(t, m);

    printf("\nXotira muvaffaqiyatli bo'shatildi.\n");

    return 0;
}

