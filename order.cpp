// order
#include <stdio.h>
#include <math.h>

int main()
{
    double n = 1000;

    printf("For n = %.0lf\n\n", n);

    printf("1. n * log2(n)        = %.2lf\n", n * log2(n));
    printf("2. 12 * sqrt(n)       = %.2lf\n", 12 * sqrt(n));
    printf("3. 1 / n              = %.10lf\n", 1 / n);
    printf("4. n^(log2(n))        = %.2e\n", pow(n, log2(n)));
    printf("5. 100n^2 + 6n        = %.2lf\n", 100 * n * n + 6 * n);
    printf("6. n^0.51             = %.2lf\n", pow(n, 0.51));
    printf("7. n^2 - 324          = %.2lf\n", n * n - 324);
    printf("8. 50n^0.5            = %.2lf\n", 50 * sqrt(n));
    printf("9. 2n^3               = %.2lf\n", 2 * n * n * n);
    printf("10. 3^n               = %.2e\n", pow(3, n));
    printf("11. 2^32 * n          = %.2lf\n", pow(2, 32) * n);
    printf("12. log2(n)           = %.2lf\n", log2(n));

    return 0;
}