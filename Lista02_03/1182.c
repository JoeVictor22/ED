#include <stdio.h>

int main(){
	int i, j, coluna;
	float resultado, matriz[12][12];
    char opc;

    scanf("%d", &coluna);
    getchar();
	scanf("%c", &opc);

    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%f", &matriz[i][j]);
        }
    }


    resultado = 0;
    for(i = 0; i < 12; i++){
        resultado+= matriz[i][coluna];
    }
    
    switch(opc){
        case 'S':
       		printf("%.1f\n", resultado);        
            break;
        case 'M':     
            printf("%.1f\n", resultado/12);        
            break;
        default:
            printf("escolheu nd");
            break;

    }
    
    return 0;
}
