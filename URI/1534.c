#include <stdio.h>

void printarMatriz(int n);

int main(){

    int n;

    while(scanf("%d", &n) != EOF){
        if(n >= 3 && n < 70){
            printarMatriz(n);
        }
    }


    return 0;
}


void printarMatriz(int n){

    int i, j, k, linha;
    int matriz[n][n];
    
    for(i = 0, j = n-1; i < n/2; i++, j--){
        k = 0;
        while(k < i){
            matriz[i][k] = 3;
            k++;
        }
        k++;
        
        matriz[i][i] = 1;
        
        while(k < j){
            matriz[i][k] = 3;
            k++;
        }
        k++;
        
        matriz[i][j] = 2;
        
        while(k < n){
            matriz[i][k] = 3;
            k++;
        }
    }
    
    if(n%2 == 1){
        matriz[i][n/2] = 2;
        k = 0;
        while(k < n/2){
            matriz[i][k] = 3;
            k++;
        }
        k++;
        while(k < n){
            matriz[i][k] = 3;
            k++;
        }
        
        linha = i+1;
    }else{
        linha = i;
    }


    for(i--, j++; linha < n; linha++, i--, j++){
        
        k = 0;
        while(k < i){
            matriz[linha][k] = 3;
            k++;
        }
        k++;
        
        matriz[linha][i] = 2;
        
        while(k < j){
            matriz[linha][k] = 3;
            k++;
        }
        k++;
        
        matriz[linha][j] = 1;
        
        while(k < n){
            matriz[linha][k] = 3;
            k++;
        }

    }


    for(i = 0; i < n; i++){
        for(j = 0 ; j < n; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");

    }


}
