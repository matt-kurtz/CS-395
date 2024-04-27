#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];

int is_clique(int vertices[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!graph[vertices[i]][vertices[j]]) {
                return 0;
            }
        }
    }
    return 1;
}

void print_matrix(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void generate_subsets(int n, int size) {
    int subset[size];
    int index[size];
    for (int i = 0; i < size; i++) {
        subset[i] = i;
        index[i] = i;
    }
    //print_matrix(n);
    while (index[0] < n - size + 1) {
        if (is_clique(subset, size)) {
            printf("Clique found of size %d\n", size);
            /*for (int i = 0; i < size; i++) {
                printf("%d ", subset[i]);
            }
            printf("\n");*/

            // Print the entire adjacency matrix, flipped
            //print_matrix(n);
            printf("\n");
            return;
        }
        int i = size - 1;
        while (i >= 0 && index[i] == n - size + i) {
            i--;
        }
        if (i < 0) {
            break;
        }
        index[i]++;
        for (int j = i + 1; j < size; j++) {
            index[j] = index[j - 1] + 1;
        }
        for (int j = 0; j < size; j++) {
            subset[j] = index[j];
        }
    }
    printf("No clique found of size %d\n", size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s number_of_vertices upper_triangle_of_adjacency_matrix\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int upper_triangle[MAX_VERTICES * (MAX_VERTICES - 1) / 2];
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        upper_triangle[i] = atoi(argv[i + 2]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            graph[i][j] = upper_triangle[index];
            graph[j][i] = upper_triangle[index];
            index++;
        }
    }
    print_matrix(n);

    for (int size = n; size > 0; size--) {
        generate_subsets(n, size);
    }

    return 0;
}

