#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
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
    BubbleSort(v, tam);
    clock_t end = clock();

    double exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.2f ms\n", exec_time);

    free(v);
    return 0;
}
