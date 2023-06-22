#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 10

int tsp_brute_force(int graph[MAX_CITIES][MAX_CITIES], int cities[], int start, int end, int num_cities) {
    int i, temp, min_cost = INT_MAX, cost;
    int opcount = 0;

    if (start == end) {
        cost = 0;
        for (i = 1; i < num_cities; i++) {
            cost += graph[cities[i - 1]][cities[i]];
            opcount++; // Increment opcount for each distance calculation
        }
        cost += graph[cities[num_cities - 1]][cities[0]];
        opcount++; // Increment opcount for the final distance calculation

        if (cost < min_cost) {
            min_cost = cost;
        }
    } else {
        for (i = start; i <= end; i++) {
            temp = cities[start];
            cities[start] = cities[i];
            cities[i] = temp;

            opcount++; // Increment opcount for each swap operation

            min_cost = tsp_brute_force(graph, cities, start + 1, end, num_cities);
            
            temp = cities[start];
            cities[start] = cities[i];
            cities[i] = temp;
        }
    }

    return opcount;
}

int main() {
    int num_cities, i, j;
    int graph[MAX_CITIES][MAX_CITIES];
    int cities[MAX_CITIES];
    int opcount;

    printf("Enter the number of cities (up to %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < num_cities; i++) {
        for (j = 0; j < num_cities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < num_cities; i++) {
        cities[i] = i;
    }

    opcount = tsp_brute_force(graph, cities, 1, num_cities - 1, num_cities);

    printf("Minimum cost: %d\n", opcount);

    return 0;
}