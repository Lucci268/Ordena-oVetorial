#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Falha de memória!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10000;
    }

    clock_t start = clock();
    BubbleSort(v, n);
    clock_t end = clock();

    double exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f ms\n", exec_time);

    free(v);
    return 0;
}
