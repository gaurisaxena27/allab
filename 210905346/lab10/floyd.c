
#include <stdio.h>
#include <stdlib.h>

void floyd(int **mat, int n, int *opCount) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                (*opCount)++;
                mat[i][j] = (mat[i][j] < (mat[i][k] + mat[k][j])) ? mat[i][j] : (mat[i][k] + mat[k][j]);
            }
        }
    }
}

void main() {
    int i, j, n, opCount = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **adjMat = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        adjMat[i] = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &adjMat[i][j]);
        }
    }

    floyd(adjMat, n, &opCount);

    printf("All pairs shortest path is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adjMat[i][j]);
        printf("\n");
    }

    printf("Operation count: %d\n", opCount);
}
