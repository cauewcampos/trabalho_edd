#include <stdio.h>
#include <stdlib.h>

void selectionSort(int v[], int n) {
    for (int i = 0; i < n; i++) {
        int index_menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[index_menor])
                index_menor = j;
        }

        int aux = v[i];
        v[i] = v[index_menor];
        v[index_menor] = aux;
    }
}

int arrayNums[11];

// função para criar um vetor com 10000 números aleatórios.
void criarNum() {
    for (int i = 0; i < 10; i++) {
        arrayNums[i] = rand() % 10;
    }
}

void imprimirArray(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    printf("Voce deseja testar os metodos de ordenacao com numeros ou palavras?\n");
    printf("1 - Numeros\n2 - Palavras\n3 - Sair\n");
    int resp;
    printf("Insira um numero: ");
    scanf("%d", &resp);

    if (resp == 1) {
        printf("Criando uma ordem de numeros aleatorios...\n");
        criarNum();

        printf("Numeros desordenados:\n");
        imprimirArray(arrayNums, 10);

        selectionSort(arrayNums, 10);

        printf("Numeros ordenados:\n");
        imprimirArray(arrayNums, 10);

    } else if (resp == 2) {
        printf("Criando uma ordem de nomes aleatorios...\n");
        printf("Ordenando os nomes...\n");
        //totalTime();
    } else {
        printf("Finalizando o programa!\n");
    }

    return 0;
}
