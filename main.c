#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int arrayNums1[100000];
int arrayNums2[100000];
int arrayNums3[100000];
int arrayNums4[100000];
double timeInsertion;
double timeQuick;
double timeBubble;
double timeSelection;

// vetor inicializado com 100 nomes diferentes.
char palavras[100][20] = {
    "Ana", "Pedro", "Lucas", "Maria", "Joao", "Camila", "Carlos", "Julia", "Paulo", "Fernanda",
    "Marcos", "Clara", "Gabriel", "Sofia", "Ricardo", "Helena", "Rafael", "Isabela", "Leonardo", "Larissa",
    "Eduardo", "Beatriz", "Thiago", "Vitoria", "Felipe", "Lucia", "Bruno", "Alice", "Roberto", "Patricia",
    "Andre", "Carolina", "Vinicius", "Mariana", "Renato", "Leticia", "Gustavo", "Gabriela", "Arthur", "Viviane",
    "Diego", "Renata", "Daniel", "Sara", "Rodrigo", "Tatiana", "Alexandre", "Luana", "Samuel", "Natalia",
    "Matheus", "Rafaela", "Igor", "Veronica", "Augusto", "Bruna", "Caio", "Elisa", "Mauricio", "Carla",
    "Henrique", "Erica", "Antonio", "Clarissa", "Fabio", "Vanessa", "Otavio", "Tatiane", "Marcelo", "Cecilia",
    "Miguel", "Isadora", "Cesar", "Joana", "Wilson", "Barbara", "Elias", "Manuela", "Flavio", "Estela",
    "Danilo", "Aline", "Hugo", "Yasmin", "Josue", "Olivia", "Vitor", "Ingrid", "Luiz", "Raquel",
    "Jorge", "Bianca", "Francisco", "Regina", "Bernardo", "Monica", "Melancia", "Abacaxi", "Laranja", "Uva",
    "Manga", "Morango", "Pera", "Banana", "Caju", "Limao", "Mamão", "Tomate", "Coco", "Amora"
};


// função para criar um vetor com 50000 numeros aleatorios.
void criarNum(){
    for(int i = 0; i < 100000; i++){
        int num = rand() % 100000;
        arrayNums1[i] = num;
        arrayNums2[i] = num;
        arrayNums3[i] = num;
        arrayNums4[i] = num;
    }
}

// METODOS DE ORDENAÇÃO
void insertionSort(int vet[], int tam) {

    clock_t start = clock();

    int i, j, aux;
        for (i = 1; i < tam; i++){
            aux = vet[i];
            j = i - 1;
            
            while((j >= 0) && (aux < vet[j])){
                vet[j+1] = vet[j];
                j--;
            }
            vet[j+1]= aux;
        }

    clock_t end = clock();
    timeInsertion = (double)(end - start) / CLOCKS_PER_SEC;

}

// MOSTRAR OS TEMPOS
void showTimes(double x){//,double y,double z, double a) {
        printf("------- TEMPOS DE EXECUCAO -------\n");
        printf("Insertion Sort: %f segundos\n", x);
//      printf("Selection Sort: %f segundos\n", y);
//      printf("Bubble Sort: %f segundos\n", z);
//      printf("Quick Sort: %f segundos\n", a);
        printf("----------------------------------\n");
}



int main () {

    printf("Voce deseja testar os metodos de ordenacao com numeros ou palavras?\n");
    printf("1 - Numeros\n2 - Palavras\n3 - Sair\n");
    int resp;
    printf("Insira um numero: ");
    scanf("%d", &resp);

    if(resp==1){
            printf("Criando uma ordem de numeros aleatorios...\n");
            criarNum();
            printf("Ordenando os numeros...\n\n");
            insertionSort(arrayNums1,100000);
            showTimes(timeInsertion);

    } else if(resp==2) {
        printf("Criando uma ordem de nomes aleatorios...\n");
        printf("Ordenando os nomes...\n");
        //totalTime();
    } else {
        printf("Finalizando o programa!\n");
    }
}

