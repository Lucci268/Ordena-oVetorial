#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tam; ++j) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }
}

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int *v = (int *)malloc(tam * sizeof(int));
    if (v == NULL) {
        printf("Falha de memória!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % 10000;
    }

    clock_t start = clock();
    selectionSort(v, tam);
    clock_t end = clock();

    double exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f ms\n", exec_time);

    free(v);
    return 0;
}

