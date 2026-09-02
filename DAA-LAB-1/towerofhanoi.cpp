// tower of Hanoi

#include <stdio.h>

int moves = 0;

void toh(int n, char source, char auxiliary, char destination)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        moves++;
        return;
    }

    toh(n - 1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n", n, source, destination);
    moves++;

    toh(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    toh(n, 'A', 'B', 'C');

    printf("\nTotal Moves = %d\n", moves);

    return 0;
}