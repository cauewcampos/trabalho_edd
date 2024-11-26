#include <stdio.h>
#include <stdlib.h>

int arrayNums[2500];

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

// vetor inicializado com 100 nomes diferentes.
char nomes[100];

// função para criar um vetor com 2500 numeros aleatorios.
void criarNum(){
    for(int i=0; i<2500; i++){
    arrayNums[i] = rand() % 2500;
    }
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
        printf("Ordenando os numeros...\n");

        //totalTime();
    } else if(resp==2) {
        printf("Criando uma ordem de nomes aleatorios...\n");
        printf("Ordenando os nomes...\n");
        //totalTime();
    } else {
        printf("Finalizando o programa!\n");
    }
}

