#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp = fopen("merge_sort_growth.txt", "w");

    fprintf(fp, "n  Merge Sort  Modified Merge Sort\n");

    for(int n = 100; n <= 1000; n += 100)
    {
        double merge = n * log2(n);
        double modified = n * (log(n) / log(3));

        fprintf(fp, "%d    %.2f     %.2f\n", n, merge, modified);
    }

    fclose(fp);

    printf("Data written to merge_sort_growth.txt\n");

    return 0;
}
