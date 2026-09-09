#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int type;
} Event;

int compareEvents(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    if (e1->year != e2->year)
        return e1->year - e2->year;
    return e1->type - e2->type;
}

int bestTimeToBeAlive(int births[], int deaths[], int n, int *best_year) {
    Event *events = malloc(2 * n * sizeof(Event));
    for (int i = 0; i < n; i++) {
        events[2 * i].year = births[i];
        events[2 * i].type = 1;
        events[2 * i + 1].year = deaths[i];
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(Event), compareEvents);

    int max_alive = 0, current_alive = 0;
    *best_year = events[0].year;

    for (int i = 0; i < 2 * n; i++) {
        current_alive += events[i].type;
        if (current_alive > max_alive) {
            max_alive = current_alive;
            *best_year = events[i].year;
        }
    }

    free(events);
    return max_alive;
}

int main() {
    int births[] = {1879, 1642, 1831, 1564, 1942};
    int deaths[] = {1955, 1727, 1879, 1642, 2018};
    int n = sizeof(births) / sizeof(births[0]);
    int best_year;

    int max_scientists = bestTimeToBeAlive(births, deaths, n, &best_year);

    printf("Best year to be alive: %d\n", best_year);
    printf("Max prominent scientists alive: %d\n", max_scientists);
    printf("Time Complexity: O(n log n)\n");
    printf("Space Complexity: O(n)\n");

    return 0;
}