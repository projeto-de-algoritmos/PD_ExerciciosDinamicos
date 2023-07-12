#include <stdio.h>
#include <stdlib.h>

int maior_subsequencia_crescente(int sequence[], int n) {
    int *lis = (int*)malloc(n * sizeof(int)); // Aloca memória para armazenar as informações de LIS
    int i, j, max = 0;

    // Inicializa a LIS com 1 em cada posição
    for (i = 0; i < n; i++)
        lis[i] = 1;

    // Calcula a LIS para cada elemento da sequência
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (sequence[i] > sequence[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    // Encontra o valor máximo na LIS
    for (i = 0; i < n; i++) {
        if (lis[i] > max)
            max = lis[i];
    }

    free(lis); // Libera a memória alocada para a LIS

    return max;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int *elements = (int*)malloc(n * sizeof(int));

        // Lê os elementos da sequência
        for (int i = 0; i < n; i++)
            scanf("%d", &elements[i]);

        int result = maior_subsequencia_crescente(elements, n);
        printf("%d\n", result);

        free(elements); // Libera a memória alocada para os elementos
    }

    return 0;
}
