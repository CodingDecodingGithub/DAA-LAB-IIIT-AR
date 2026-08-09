#include <stdio.h>#include <math.h>

int main(){FILE *fp = fopen("dictionary_operations.txt", "w");

fprintf(fp, "n UA_Search UA_Insert UA_Delete UA_Max UA_Min UA_Pred UA_Succ ");
fprintf(fp, "SA_Search SA_Insert SA_Delete SA_Max SA_Min SA_Pred SA_Succ ");
fprintf(fp, "SUL_Search SUL_Insert SUL_Delete SUL_Max SUL_Min SUL_Pred SUL_Succ ");
fprintf(fp, "SSL_Search SSL_Insert SSL_Delete SSL_Max SSL_Min SSL_Pred SSL_Succ ");
fprintf(fp, "DUL_Search DUL_Insert DUL_Delete DUL_Max DUL_Min DUL_Pred DUL_Succ ");
fprintf(fp, "DSL_Search DSL_Insert DSL_Delete DSL_Max DSL_Min DSL_Pred DSL_Succ\n");

for(int n = 100; n <= 1000; n += 100)
{
    double logn = log2(n);

    /* Unsorted Array */
    double UA_Search = n;
    double UA_Insert = 1;
    double UA_Delete = n;
    double UA_Max = n;
    double UA_Min = n;
    double UA_Pred = n;
    double UA_Succ = n;

    /* Sorted Array */
    double SA_Search = logn;
    double SA_Insert = n;
    double SA_Delete = n;
    double SA_Max = 1;
    double SA_Min = 1;
    double SA_Pred = logn;
    double SA_Succ = logn;

    /* Singly Linked Unsorted List */
    double SUL_Search = n;
    double SUL_Insert = 1;
    double SUL_Delete = n;
    double SUL_Max = n;
    double SUL_Min = n;
    double SUL_Pred = n;
    double SUL_Succ = n;

    /* Singly Linked Sorted List */
    double SSL_Search = n;
    double SSL_Insert = n;
    double SSL_Delete = n;
    double SSL_Max = n;
    double SSL_Min = 1;
    double SSL_Pred = n;
    double SSL_Succ = n;

    /* Doubly Linked Unsorted List */
    double DUL_Search = n;
    double DUL_Insert = 1;
    double DUL_Delete = 1;
    double DUL_Max = n;
    double DUL_Min = n;
    double DUL_Pred = n;
    double DUL_Succ = n;

    /* Doubly Linked Sorted List */
    double DSL_Search = n;
    double DSL_Insert = n;
    double DSL_Delete = 1;
    double DSL_Max = 1;
    double DSL_Min = 1;
    double DSL_Pred = 1;
    double DSL_Succ = 1;

    fprintf(fp,
    "%d "
    "%.2f %.2f %.2f %.2f %.2f %.2f %.2f "
    "%.2f %.2f %.2f %.2f %.2f %.2f %.2f "
    "%.2f %.2f %.2f %.2f %.2f %.2f %.2f "
    "%.2f %.2f %.2f %.2f %.2f %.2f %.2f "
    "%.2f %.2f %.2f %.2f %.2f %.2f %.2f "
    "%.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",

    n,

    UA_Search, UA_Insert, UA_Delete, UA_Max, UA_Min, UA_Pred, UA_Succ,
    SA_Search, SA_Insert, SA_Delete, SA_Max, SA_Min, SA_Pred, SA_Succ,
    SUL_Search, SUL_Insert, SUL_Delete, SUL_Max, SUL_Min, SUL_Pred, SUL_Succ,
    SSL_Search, SSL_Insert, SSL_Delete, SSL_Max, SSL_Min, SSL_Pred, SSL_Succ,
    DUL_Search, DUL_Insert, DUL_Delete, DUL_Max, DUL_Min, DUL_Pred, DUL_Succ,
    DSL_Search, DSL_Insert, DSL_Delete, DSL_Max, DSL_Min, DSL_Pred, DSL_Succ);
}

fclose(fp);

printf("Data written to dictionary_operations.txt\n");

return 0;

}
