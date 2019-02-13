#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(){

    int vetor[30];
    int i;

    srand(time(NULL));

    for(i = 0; i < 30; i++){
        vetor[i] = rand() % 50 + 1;
    }

    printf("VETOR GERADO:\n");
    for(i = 0; i < 30; i++){
        printf("%d ", vetor[i]);
    }

    for(i = 0; i < 30; i+=2){
        vetor[i] *= 2;
    }
    for(i = 1; i < 30; i+=2){
        vetor[i] *= 5;
    }

    printf("\n\nVETOR APOS LEI DE FORMACAO:\n");
    for(i = 0; i < 30; i++){
        printf("%d ", vetor[i]);
    }
	
	int key,j;
    for(i = 1 ; i < 30; i++){
        key = vetor[i];
        j = i-1;
        while(key< vetor[j] && j >= 0){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = key;
    }

   	printf("\n\nVETOR APOS ORDENACAO:\n");
    for(i = 0; i < 30; i++){
        printf("%d ", vetor[i]);
    }

    int pesquisa;
    printf("\n\nDigite o numero a ser pesquisado!\n");
    scanf("%d", &pesquisa);

    int meio, inicio, fim;
    bool achou;
    inicio = 0;
    fim = 30;
    achou = false;
    while(inicio <= fim){
        meio = (inicio+fim)/2;

        if(vetor[meio] == pesquisa){
            achou = true;
            break;
        }else if(vetor[meio] > pesquisa){
            fim = meio-1;
        }else{
            inicio = meio+1;
        }
        
    }
    if(achou == true){
        printf("O numero esta na posicao %d\n", meio);
    }else{
        printf("O numero nao existe no vetor\n");
    }

    return 0;
}
