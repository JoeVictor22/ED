#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int a[25];
    int b[25];
    int c[50];
    int i, pesquisa;
    
    srand(time(NULL));
    
    for(i = 0; i < 25; i++){
        a[i] = rand() % 1000 +1;
        b[i] = rand() % 1000 +1;
    }

    for(i = 0; i < 25; i++){
        c[i] = a[i];
        c[i+25] = b[i];
    }   

	printf("Vetor A\n");
    for(i = 0; i < 25; i++){
        printf("%d ", a[i]);
    }
    printf("\n\n");
    printf("Vetor B\n");
    for(i = 0; i < 25; i++){
        printf("%d ", b[i]);
    } 
    printf("\n\n");
    printf("Vetor C\n");
    for(i = 0; i < 50; i++){
        printf("%d ", c[i]);
    }
    
    printf("\nDigite o numero a ser buscado!\n");
    scanf("%d", &pesquisa);
    
    for(i = 0; i < 50; i++){
		if(c[i] == pesquisa){
			break;
		}
	}
	if(i >= 50){
		printf("O numero nao existe no vetor!");
	}else{
		printf("O numero esta na posicao %d do vetor!", i);
	}


    return 0;
}
