#include <stdio.h>

void quick(int *vetor, int inicio, int fim);

int main(){
    int n,i,m,igual;
    int vetor[1000], vetor1[1000];

    scanf("%d", &n);


    while(n--){
        scanf("%d", &m);
        igual = 0;
        for(i = 0; i < m; i++){
            scanf("%d", &vetor[i]);
            vetor1[i] = vetor[i];
        }
        quick(vetor, 0, m-1);

        for(i = 0; i < m; i++){
            if(vetor[i] == vetor1[i]){
                igual++;
        	}
        }
        printf("%d\n", igual);
    }

    return 0;
}


void quick(int *vetor, int inicio, int fim){
    int aux;
    int meio = vetor[(inicio + fim)/2];
    int ini = inicio;
    int fim1 = fim;

    while(inicio <= fim){
        while(vetor[inicio] > meio){
            inicio++;
        }
        while(vetor[fim] < meio){
            fim--;
        }
        if(inicio <= fim){
            aux = vetor[inicio];
            vetor[inicio] = vetor[fim];
            vetor[fim] = aux;
            inicio++;
            fim--;
        }
    }
    if(ini < fim){
        quick(vetor, ini, fim);
    }
    if(inicio < fim1){
        quick(vetor,inicio, fim1);
    }

}
