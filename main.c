#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// AFIM DE FACILITAR OS TESTES, APLICAMOS O DEFINE PARA ALTERAR APENAS UMA VEZ
#define TAMANHO_ARRAY 100000
#define TAMANHO_PALAVRAS 16

int arrayNums1[TAMANHO_ARRAY];
int arrayNums2[TAMANHO_ARRAY];
int arrayNums3[TAMANHO_ARRAY];
int arrayNums4[TAMANHO_ARRAY];
double timeInsertion = 0;
double timeQuick = 0;
double timeBubble = 0;
double timeSelection = 0;

char palavras[TAMANHO_PALAVRAS][800] = {
    "amor", "chuva", "a  c  r y z", "amorz", "dado", "felicidade", "lucas a", "zebra", "energia", "garrafa", "historia", "infinito", "brisa", "jasmim", "lucas moreira", "lucas jr"
};

// FUNC QUE CRIA QUANTIDADE DITA NO DEFINE DE NUMEROS ALEATÓRIOS
void criarNum(){
    for(int i = 0; i < TAMANHO_ARRAY; i++){
        int num = rand() % TAMANHO_ARRAY;
        arrayNums1[i] = num;
        arrayNums2[i] = num;
        arrayNums3[i] = num;
        arrayNums4[i] = num;
    }
}

// METODOS DE ORDENAÇÃO PARA NUMEROS
void insertionSort(int vet[], int tam) {
    clock_t start = clock();
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        aux = vet[i];
        j = i - 1;
        while ((j >= 0) && (aux < vet[j])) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
    clock_t end = clock();
    timeInsertion = (double)(end - start) / CLOCKS_PER_SEC;
}

void selectionSort(int vet[], int tam) {
    clock_t start = clock();
    for (int i = 0; i < tam; i++) {
        int index_menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[index_menor])
                index_menor = j;
        }
        int aux = vet[i];
        vet[i] = vet[index_menor];
        vet[index_menor] = aux;
    }
    clock_t end = clock();
    timeSelection = (double)(end - start) / CLOCKS_PER_SEC;
}

void bubbleSort(int vet[], int tam) {
    clock_t start = clock();
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        for (j = 0; j < tam - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
    clock_t end = clock();
    timeBubble = (double)(end - start) / CLOCKS_PER_SEC;
}

void quickSort(int vet[], int low, int high) {
    // Implementação não necessária para este código, mantendo o espaço reservado.
}

// METODOS DE ORDENAÇÃO PARA STRING
void selectionSortWords(char vet[][800], int tam) {
    clock_t start = clock();
    for (int i = 0; i < tam - 1; i++) {
        int index_menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (strcmp(vet[j], vet[index_menor]) < 0) {
                index_menor = j;
            }
        }
        char temp[800];
        strcpy(temp, vet[i]);
        strcpy(vet[i], vet[index_menor]);
        strcpy(vet[index_menor], temp);
    }
    clock_t end = clock();
    timeSelection = (double)(end - start) / CLOCKS_PER_SEC;
}

void quickSortWords(char vet[][800], int low, int high) {
    clock_t start = clock();
    if (low < high) {
        int pi = partindoPalavras(vet, low, high);
        quickSortWords(vet, low, pi - 1);
        quickSortWords(vet, pi + 1, high);
    }
    clock_t end = clock();
    timeQuick = (double)(end - start) / CLOCKS_PER_SEC;
}

int partindoPalavras(char arr[][800], int low, int high) {
    char pivot[800];
    strcpy(pivot, arr[high]);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            trocaPalavra(&arr[i], &arr[j]);
        }
    }
    trocaPalavra(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void trocaPalavra(char xp[][800], char yp[][800]) {
    char temp[800];
    strcpy(temp, xp[0]);
    strcpy(xp[0], yp[0]);
    strcpy(yp[0], temp);
}

void showTimes(double x, double y, double z, double a) {
    printf(" ___________________________________ \n");
    printf("|       TEMPOS DE EXECUCAO          |\n");
    printf("| Insertion Sort: %.6f segundos |\n", x);
    printf("| Selection Sort: %.6f segundos |\n", y);
    printf("| Bubble Sort   : %.6f segundos |\n", z);
    printf("| Quick Sort    : %.6f segundos |\n", a);
    printf(" ___________________________________ \n");
    timeInsertion = 0;
    timeQuick = 0;
    timeBubble = 0;
    timeSelection = 0;
}

void printWords(char vet[][800], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%s\n", vet[i]);
    }
}

int main() {
    int resp = 0;
    while (resp != 3) {
        printf("======================================================================\n");
        printf(" Voce deseja testar os metodos de ordenacao com numeros ou palavras?\n");
        printf(" 1 - Numeros\n 2 - Palavras\n 3 - Sair\n");
        printf("======================================================================\n");
        printf("Insira um numero: ");
        scanf("%d", &resp);

        if (resp == 1) {
            printf("\nCriando uma ordem de numeros aleatorios...\n");
            criarNum();
            printf("Ordenando os numeros...\n");
            insertionSort(arrayNums1, TAMANHO_ARRAY);
            selectionSort(arrayNums2, TAMANHO_ARRAY);
            bubbleSort(arrayNums3, TAMANHO_ARRAY);
            showTimes(timeInsertion, timeSelection, timeBubble, timeQuick);
        }
        else if (resp == 2) {
            printf("\nOrdenando os nomes...\n");

            printWords(palavras, TAMANHO_PALAVRAS);

            selectionSortWords(palavras, TAMANHO_PALAVRAS);

            printf("\nPalavras apos a ordenacao:\n");
            printWords(palavras, TAMANHO_PALAVRAS);

            showTimes(timeInsertion, timeSelection, timeBubble, timeQuick);
        }
    }
    printf("\nObrigado por utilizar o programa!\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// AFIM DE FACILITAR OS TESTES, APLICAMOS O DEFINE PARA ALTERAR APENAS UMA VEZ
#define TAMANHO_ARRAY 100000
#define TAMANHO_PALAVRAS 16

int arrayNums1[TAMANHO_ARRAY];
int arrayNums2[TAMANHO_ARRAY];
int arrayNums3[TAMANHO_ARRAY];
int arrayNums4[TAMANHO_ARRAY];
double timeInsertion = 0;
double timeQuick = 0;
double timeBubble = 0;
double timeSelection = 0;

char palavras[TAMANHO_PALAVRAS][800] = {
    "amor", "chuva", "a  c  r y z", "amorz", "dado", "felicidade", "lucas a", "zebra", "energia", "garrafa", "historia", "infinito", "brisa", "jasmim", "lucas moreira", "lucas jr"
};

// FUNC QUE CRIA QUANTIDADE DITA NO DEFINE DE NUMEROS ALEATÓRIOS
void criarNum(){
    for(int i = 0; i < TAMANHO_ARRAY; i++){
        int num = rand() % TAMANHO_ARRAY;
        arrayNums1[i] = num;
        arrayNums2[i] = num;
        arrayNums3[i] = num;
        arrayNums4[i] = num;
    }
}

// METODOS DE ORDENAÇÃO PARA NUMEROS
void insertionSort(int vet[], int tam) {
    clock_t start = clock();
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        aux = vet[i];
        j = i - 1;
        while ((j >= 0) && (aux < vet[j])) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
    clock_t end = clock();
    timeInsertion = (double)(end - start) / CLOCKS_PER_SEC;
}

void selectionSort(int vet[], int tam) {
    clock_t start = clock();
    for (int i = 0; i < tam; i++) {
        int index_menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[index_menor])
                index_menor = j;
        }
        int aux = vet[i];
        vet[i] = vet[index_menor];
        vet[index_menor] = aux;
    }
    clock_t end = clock();
    timeSelection = (double)(end - start) / CLOCKS_PER_SEC;
}

void bubbleSort(int vet[], int tam) {
    clock_t start = clock();
    int i, j, aux;
    for (i = 1; i < tam; i++) {
        for (j = 0; j < tam - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
    clock_t end = clock();
    timeBubble = (double)(end - start) / CLOCKS_PER_SEC;
}

void quickSort(int vet[], int low, int high) {
    // Implementação não necessária para este código, mantendo o espaço reservado.
}

// METODOS DE ORDENAÇÃO PARA STRING
void selectionSortWords(char vet[][800], int tam) {
    clock_t start = clock();
    for (int i = 0; i < tam - 1; i++) {
        int index_menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (strcmp(vet[j], vet[index_menor]) < 0) {
                index_menor = j;
            }
        }
        char temp[800];
        strcpy(temp, vet[i]);
        strcpy(vet[i], vet[index_menor]);
        strcpy(vet[index_menor], temp);
    }
    clock_t end = clock();
    timeSelection = (double)(end - start) / CLOCKS_PER_SEC;
}

void quickSortWords(char vet[][800], int low, int high) {
    clock_t start = clock();
    if (low < high) {
        int pi = partindoPalavras(vet, low, high);
        quickSortWords(vet, low, pi - 1);
        quickSortWords(vet, pi + 1, high);
    }
    clock_t end = clock();
    timeQuick = (double)(end - start) / CLOCKS_PER_SEC;
}

int partindoPalavras(char arr[][800], int low, int high) {
    char pivot[800];
    strcpy(pivot, arr[high]);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            trocaPalavra(&arr[i], &arr[j]);
        }
    }
    trocaPalavra(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void trocaPalavra(char xp[][800], char yp[][800]) {
    char temp[800];
    strcpy(temp, xp[0]);
    strcpy(xp[0], yp[0]);
    strcpy(yp[0], temp);
}

void showTimes(double x, double y, double z, double a) {
    printf(" ___________________________________ \n");
    printf("|       TEMPOS DE EXECUCAO          |\n");
    printf("| Insertion Sort: %.6f segundos |\n", x);
    printf("| Selection Sort: %.6f segundos |\n", y);
    printf("| Bubble Sort   : %.6f segundos |\n", z);
    printf("| Quick Sort    : %.6f segundos |\n", a);
    printf(" ___________________________________ \n");
    timeInsertion = 0;
    timeQuick = 0;
    timeBubble = 0;
    timeSelection = 0;
}

void printWords(char vet[][800], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%s\n", vet[i]);
    }
}

int main() {
    int resp = 0;
    while (resp != 3) {
        printf("======================================================================\n");
        printf(" Voce deseja testar os metodos de ordenacao com numeros ou palavras?\n");
        printf(" 1 - Numeros\n 2 - Palavras\n 3 - Sair\n");
        printf("======================================================================\n");
        printf("Insira um numero: ");
        scanf("%d", &resp);

        if (resp == 1) {
            printf("\nCriando uma ordem de numeros aleatorios...\n");
            criarNum();
            printf("Ordenando os numeros...\n");
            insertionSort(arrayNums1, TAMANHO_ARRAY);
            selectionSort(arrayNums2, TAMANHO_ARRAY);
            bubbleSort(arrayNums3, TAMANHO_ARRAY);
            showTimes(timeInsertion, timeSelection, timeBubble, timeQuick);
        }
        else if (resp == 2) {
            printf("\nOrdenando os nomes...\n");

            printWords(palavras, TAMANHO_PALAVRAS);

            selectionSortWords(palavras, TAMANHO_PALAVRAS);

            printf("\nPalavras apos a ordenacao:\n");
            printWords(palavras, TAMANHO_PALAVRAS);

            showTimes(timeInsertion, timeSelection, timeBubble, timeQuick);
        }
    }
    printf("\nObrigado por utilizar o programa!\n");
    return 0;
}
