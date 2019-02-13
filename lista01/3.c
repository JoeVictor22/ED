#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int a[5][4];
    int b[4][3];
    int i,j,k;

    int c[5][3];

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            c[i][j] = 0;
        }
    }

    srand(time(NULL));

    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){
            a[i][j] = rand() % 9 + 1;
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            b[i][j] = rand() % 9 + 1;
        }
    }

    printf("MATRIZ A\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMATRIZ B\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

    //linhas matriz resultante
	for(i = 0; i < 5; i++){
        //colunas matriz resultante
		for(j = 0; j < 3; j++){
            //colunas matriz A = linhas matriz B
            for(k = 0; k < 4; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
		}
	}

    printf("\nMATRIZ AxB\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }




    return 0;
}
