
#include "ekub_ekuk.h"
#include <stdlib.h>

void ekub_ekuk(int a, int b, int *ekub, int *ekuk) {
    long long x = llabs((long long)a);
    long long y = llabs((long long)b);

    if (x == 0 && y == 0) {
        *ekub = 0;
        *ekuk = 0;
        return;
    }

    long long m = x;
    long long n = y;

    while (n != 0) {
        long long r = m % n;
        m = n;
        n = r;
    }

    *ekub = (int)m;

    if (m == 0) {
        *ekuk = 0;
    } else {
        long long result = (x / m) * y;

        if (result > 2147483647LL) {
            *ekuk = -1;
        } else {
            *ekuk = (int)result;
        }
    }
}
