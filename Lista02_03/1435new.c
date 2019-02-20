#include <stdio.h>
#include <stdbool.h>

void printarNumero(int *numero, int *coluna);

int main(){

	int n,posicao1, posicao2, fim, numero;
	bool impar;
	
	n = 1;
	while(n != 0){
		scanf("%d", &n);
	
		impar = false;	
		if(n%2 == 1 ) {
			n = n/2;
			n++;
			impar = true;
		}else{
			n = n/2;
		}	   
		
		int matriz[n][n];	 
	    //cria matriz
	    posicao2 = 0;
	    for(numero = 1; numero <= n; numero++){
	    	fim = n;
             
	        //atribui os 4 cantos
	        matriz[posicao2][posicao2] = numero;        
	
	        //atribui laterais
	        for(posicao1 = posicao2+1; posicao1 < fim; posicao1++){
	            matriz[posicao1][posicao2] = numero;
	            matriz[posicao2][posicao1] = numero;
	        }
	        posicao2++;
	    }
	    	
        //print
		if(impar){
			//print impar
			for(posicao1 = 0; posicao1 < n-1; posicao1++){
		        for(posicao2 = 0; posicao2 < n; posicao2++){
		            printarNumero(&matriz[posicao1][posicao2], &posicao2);  
		        }
		        for(posicao2 = n-2; posicao2 >= 0; posicao2--){
		            printf(" %3d", matriz[posicao1][posicao2]);
		        }
		        printf("\n");
		    }
			for(posicao1 = n-1; posicao1 >= 0; posicao1--){
		    	for(posicao2 = 0; posicao2 < n-1; posicao2++){
		            printarNumero(&matriz[posicao1][posicao2], &posicao2);    
		        }
		        for(posicao2 = n-1; posicao2 >= 0; posicao2--){
		            printf(" %3d", matriz[posicao1][posicao2]);
		        }
		        printf("\n");
		    }
			printf("\n");				
		}else{
			//print par
			for(posicao1 = 0; posicao1 < n; posicao1++){
		        for(posicao2 = 0; posicao2 < n; posicao2++){
		            printarNumero(&matriz[posicao1][posicao2], &posicao2);  
		        }
		        for(posicao2 = n-1; posicao2 >= 0; posicao2--){
		            printf(" %3d", matriz[posicao1][posicao2]);
		        }
		        printf("\n");
		    }
			for(posicao1 = n-1; posicao1 >= 0; posicao1--){
		    	for(posicao2 = 0; posicao2 < n; posicao2++){
		            printarNumero(&matriz[posicao1][posicao2], &posicao2);    
		        }
		        for(posicao2 = n-1; posicao2 >= 0; posicao2--){
		            printf(" %3d", matriz[posicao1][posicao2]);
		        }
		        printf("\n");
		    }
			printf("\n");	
		}		
	}
	
    return 0;
}

void printarNumero(int *numero, int *coluna){
    if(coluna == 0){
        printf("%3d", *numero);    
    }else{
        printf(" %3d", *numero);
    }

}
