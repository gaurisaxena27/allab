#include <stdio.h>
#include <string.h>

int bruteForceStringMatch(const char text[], const char pattern[], int *opcount) {
    int n = strlen(text);
    int m = strlen(pattern);
    *opcount = 0; // Initialize opcount to 0
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            (*opcount)++;
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) // Pattern found at index i
            return i;
    }
    return -1; // Pattern not found
}

int main() {
    char text[100];
    char pattern[50];
    int opcount;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    int index = bruteForceStringMatch(text, pattern, &opcount);

    if (index != -1)
        printf("Pattern found at index: %d\n", index);
    else
        printf("Pattern not found\n");

    printf("Opcount: %d\n", opcount);

    return 0;
}