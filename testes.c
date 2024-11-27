#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int arrayNums[50000];
double timeTaken;

void criarNum(){
    for(int i=0; i<50000; i++){
    arrayNums[i] = rand() % 50000;
    }
}
int insercao (int vet[], int tam){
    clock_t start = clock();
    int i, j, x;
    for (i=2; i<=tam; i++){
	x = vet[i];
	j=i-1;
	vet[0] = x;
	while (x < vet[j]){
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = x;
    }

    clock_t end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
}

int main () {
    int i = 0;
    criarNum();
    int tam = sizeof(arrayNums) / sizeof(arrayNums[0]);
    insercao(arrayNums,tam);
     printf("\nTempo de execução da ordenação: %f segundos\n", timeTaken);




}


