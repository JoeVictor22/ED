#include <stdio.h>

void printarMatriz(int* n);
void printarNumero(int* numero, int* coluna);

int main(){
 	int n;    
    scanf("%d", &n);
    
    while(n != 0){
		printarMatriz(&n); 
		printf("\n");  
        scanf("%d", &n);
    }
    return 0;
}

void printarMatriz(int* n){

    int linha,coluna;
    int numero;
    short int key;

    for(linha = 0; linha < *n; linha++){
    	
	    numero = linha + 1;
        coluna = 0;
        key = 0;
        
        while(coluna < *n){
		    printarNumero(&numero, &coluna);           
		    if(numero == 1){
                key = 1;
                numero++;
            }else if(!key){
                numero--;
            }else{
                numero++;
            }
            coluna++;
        }
        printf("\n");
    }
}

void printarNumero(int* numero, int* coluna){
	
	if(*coluna == 0){
		if(*numero < 10){
	   		printf("  %d", *numero);	
		}else if(*numero < 100 ){
			printf(" %d", *numero);
		}else{
			printf("%d",*numero);
		}	
	}else{
		if(*numero < 10){
	   		printf("   %d",*numero);	
		}else if(*numero < 100 ){
			printf("  %d",*numero);
		}else{
			printf(" %d", *numero);
		}
	}
}
