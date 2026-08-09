#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp = fopen("merge_k_arrays.txt", "w");

    fprintf(fp, "k Method1 Method2\n");

    int n = 1000;

    for(int k = 2; k <= 64; k *= 2)
    {
        double method1 = n * k * k;
        double method2 = n * k * log2(k);

        fprintf(fp, "%d %.2f %.2f\n", k, method1, method2);
    }

    fclose(fp);

    printf("Data written to merge_k_arrays.txt\n");

    return 0;
}
