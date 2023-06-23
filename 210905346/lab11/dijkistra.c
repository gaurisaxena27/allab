#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define max 9

int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int n) {
    printf("\nDistance from source:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[max][max], int src, int n) {
    int dist[max];
    bool sptSet[max];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n);
}

int main() {
    int n, graph[max][max];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("\nEnter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, n);

    return 0;
}