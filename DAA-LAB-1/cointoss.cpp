// coin toss
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i;
    int fairHeads = 0, biasedHeads = 0;

    printf("Enter the number of coin tosses: ");
    scanf("%d", &n);

    srand(time(NULL)); 

    for(i = 0; i < n; i++)
    {
        if(rand() % 2 == 0) 
        {
            fairHeads++;
        }
    }

    for(i = 0; i < n; i++)
    {
        double r = (double)rand() / RAND_MAX;

        if(r < 0.7)   
        {
            biasedHeads++;
        }
    }

    printf("Fair Coin:\n");
    printf("Heads = %d\n", fairHeads);
    printf("Tails = %d\n", n - fairHeads);
    printf("Probability of Head = %.4f\n\n", (double)fairHeads / n);

    printf("Biased Coin (70%% Head):\n");
    printf("Heads = %d\n", biasedHeads);
    printf("Tails = %d\n", n - biasedHeads);
    printf("Probability of Head = %.4f\n", (double)biasedHeads / n);

    return 0;
}