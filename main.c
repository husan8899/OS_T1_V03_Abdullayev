#include <stdio.h>
void ekub_ekuk(int a, int b, int *ekub, int *ekuk)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    if (a == 0 && b == 0) {
        *ekub = 0;
        *ekuk = 0;
        return;
    }

    int x = a, y = b;

    while (y != 0) {
        int qoldiq = x % y;
        x = y;
        y = qoldiq;
    }

    *ekub = x;

    if (x == 0)
        *ekuk = 0;
    else
        *ekuk = (a / x) * b;
}

int main(void)
{
    int a, b, ekub, ekuk;

    printf("Ikkita butun son kiriting: ");

    if (scanf("%d %d", &a, &b) != 2) {
        printf("Xato: butun son kiriting!\n");
        return 1;
    }

    if (a == 0 && b == 0) {
        printf("Xato: ikkala son ham 0 bo'lishi mumkin emas!\n");
        return 1;
    }

    ekub_ekuk(a, b, &ekub, &ekuk);

    printf("EKUB = %d\n", ekub);
    printf("EKUK = %d\n", ekuk);

    return 0;
}
