#include <stdio.h>

int main(){

    int n,i;

    scanf("%d", &n);

    int vetor[n];
    int posicao;

    scanf("%d", &vetor[i]);
    int menor = vetor[i];

    for(i = 1 ; i < n; i++){
    
        scanf("%d", &vetor[i]);    
        if(vetor[i] < menor){
            menor = vetor[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
