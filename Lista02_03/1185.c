#include <stdio.h>

int main(){

    int i,j,fim;
    char opc;
    float matriz[12][12], resultado;

    scanf("%c", &opc);

    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%f", &matriz[i][j]);
        }
    }

	resultado = 0;
    fim = 11;
    for(i = 0; i < 11; i++){
        for(j = 0; j < fim; j++){
            resultado += matriz[i][j];
        }
        fim--;
    }

    switch(opc){
        case 'S':
            printf("%.1f\n", resultado);
            break;
        case 'M':
            printf("%.1f\n", resultado/66);
            break;
        default:
            printf("nao escolheu nd\n");
            break;

    }

    return 0;
}
