#include <stdio.h>
#include "ekub_ekuk.h"

int main(void) {
    int a, b;
    int ekub, ekuk;

    printf("Ikkita butun son kiriting: ");

    if (scanf("%d %d", &a, &b) != 2) {
        printf("Xato: butun son kiriting!\n");
        return 1;
    }

    if (a == 0 && b == 0) {
        printf("Xato: ikkala son ham 0 bo'lishi mumkin emas.\n");
        return 1;
    }

    ekub_ekuk(a, b, &ekub, &ekuk);

    printf("EKUB = %d\n", ekub);
    printf("EKUK = %d\n", ekuk);

    return 0;
}
