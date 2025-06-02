#include "random_factorial.h"

int factorial(int n) {
    if (n < 0) {
        fprintf(stderr, "Error: Negative input not allowed, your input: %d.\n", n);
        fflush(stderr);
        return -1;
    }

    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}