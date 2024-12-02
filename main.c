#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// AFIM DE FACILITAR OS TESTES, APLICAMOS O DEFINE PARA ALTERAR APENAS UMA VEZ
#define TAMANHO_ARRAY 15
#define TAMANHO_PALAVRAS 8000

int arrayNums1[TAMANHO_ARRAY];
int arrayNums2[TAMANHO_ARRAY];
int arrayNums3[TAMANHO_ARRAY];
int arrayNums4[TAMANHO_ARRAY];
double timeInsertion = 0;
double timeQuick = 0;
double timeBubble = 0;
double timeSelection = 0;

char palavras[TAMANHO_PALAVRAS][800] = {
    // ... (Aqui você pode inserir ou modificar as suas 8000 palavras)
    "amor", "brisa", "chuva", "dado", "energia", "felicidade", "garrafa", "história", "infinito", "jasmim",
    // ... (Adicione as 7990 palavras restantes aqui)
};


void criarNum() {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        int num = rand() % TAMANHO_ARRAY;
        printf("%d ", num);
        arrayNums1[i] = num;
        arrayNums2[i] = num;
        arrayNums3[i] = num;
        arrayNums4[i] = num;
    }
}

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


void quickSort(int vet[], int low, int high) {
    clock_t start = clock();
    printf("low %d --  high %d | QUICK SORT\n", low, high);
    if (low < high) {
        int pi = partition(vet, low, high);
        printf("pi %d | partition \n", pi);
        quickSort(vet, low, pi - 1);
        quickSort(vet, pi + 1, high);
    }
    clock_t end = clock();

    timeQuick = (double)(end - start) / CLOCKS_PER_SEC;
}

int partition(int arr[], int low, int high) {
    int pivo = arr[high];
    printf("pivo %d | partition \n", pivo);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        printf("j = %d // arr[j] %d -- i = %d // high -1 %d | partition \n", j,arr[j], i, high - 1);
        if (arr[j] < pivo) {
            i++;
        printf("arr[j] %d // %d -- arr[i] %d // %d | partition \n", arr[j], j, arr[i], i);
            swap(&arr[i], &arr[j]);
        }
        printf("Nao e maior que o pivo \n\n");
    }
    printf("Saiu do for \n \n");
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortWords(char vet[][800], int low, int high) {
    clock_t start = clock();
    if (low < high) {
        int pi = partitionWords(vet, low, high);
        quickSortWords(vet, low, pi - 1);
        quickSortWords(vet, pi + 1, high);
    }
    clock_t end = clock();
    timeQuick = (double)(end - start) / CLOCKS_PER_SEC;
}

int partitionWords(char arr[][800], int low, int high) {
    char pivot[800];
    strcpy(pivot, arr[high]);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swapWords(&arr[i], &arr[j]);
        }
    }
    swapWords(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    printf("temp %d -- %d // %x| swap \n", temp, *yp, yp);
    *xp = *yp;
    *yp = temp;
}

void swapWords(char xp[][800], char yp[][800]) {
    char temp[800];
    strcpy(temp, xp[0]);
    strcpy(xp[0], yp[0]);
    strcpy(yp[0], temp);
}

void mostrarNumeros(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void showTimes(double x, double y, double z, double a) {
    printf(" ___________________________________ \n");
    printf("|       TEMPOS DE EXECUCAO          |\n");
    printf("| Insertion Sort: %f segundos |\n", x);
    printf("| Selection Sort: %f segundos |\n", y);
    printf("| Bubble Sort   : %f segundos |\n", z);
    printf("| Quick Sort    : %f segundos |\n", a);
    printf(" ___________________________________ \n\n");
    timeInsertion = 0;
    timeQuick = 0;
    timeBubble = 0;
    timeSelection = 0;
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
            printf("\nCriando uma ordem de numeros aleatorios...\n\n");
            criarNum();
            printf("Ordenando os numeros...\n\n");
            insertionSort(arrayNums1, TAMANHO_ARRAY);
            selectionSort(arrayNums2, TAMANHO_ARRAY);
            bubbleSort(arrayNums3, TAMANHO_ARRAY);
            quickSort(arrayNums4, 0, TAMANHO_ARRAY -1);

            printf("\nNumeros ordenados:\n");
            printf("Insertion Sort: ");
            mostrarNumeros(arrayNums1, TAMANHO_ARRAY);

            printf("Selection Sort: ");
            mostrarNumeros(arrayNums2, TAMANHO_ARRAY);

            printf("Bubble Sort: ");
            mostrarNumeros(arrayNums3, TAMANHO_ARRAY);

            printf("Quick Sort: ");
            mostrarNumeros(arrayNums4, TAMANHO_ARRAY);

            showTimes(timeInsertion, timeSelection, timeBubble, timeQuick);
        }
        else if (resp == 2) {
            printf("\nOrdenando os nomes...\n\n");
            selectionSortWords(palavras, TAMANHO_PALAVRAS);
            quickSortWords(palavras, 0, TAMANHO_PALAVRAS -1); //Teste do quickSort para strings
            showTimes(timeInsertion, timeSelection, timeBubble, timeQuick);
        }
        else if (resp != 3) {
            printf("\nOpcao invalida!\n");
        }
    }
    printf("\nObrigado por utilizar o programa!\n");
    return 0;
}
