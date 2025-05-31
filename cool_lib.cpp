#include <iostream>

#include "lib/random_factorial.h"

namespace cool_library {
    int whatsup(const int n) {
        printf("whatsup() called :)\n");

        const int result = factorial(n);
        printf("factorial(%d) = %d\n", n, result);

        fflush(stdout);
        return result;
    }
}