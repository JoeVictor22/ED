#include <stdio.h>

int main(){

	int n, posicao1, posicao2, fim, fimMatriz, numero;
	
	n = 1;
	while(n != 0){
		scanf("%d", &n);

	
	    int matriz[n][n];
	
	
	    fim = n-1;
	    fimMatriz = fim;
	    posicao2 = 0;
	
	    for(numero = 1; numero <= n/2; numero++){
	        
	        
	        //atribui os 4 cantos
	        matriz[posicao2][posicao2] = numero;        
	        matriz[fim][fim] = numero;
	        matriz[posicao2][fimMatriz - posicao2] = numero;
	        matriz[fimMatriz - posicao2][posicao2] = numero;
	        
	        //atribui laterais
	        for(posicao1 = posicao2+1; posicao1 < fim; posicao1++){
	            matriz[posicao1][posicao2] = numero;
	            matriz[posicao2][posicao1] = numero;
	            matriz[fimMatriz - posicao1][fim] = numero;
	            matriz[fim][fimMatriz - posicao1] = numero;
	        }
	        
	        posicao2++;
	        fim--;
	        
	    }
	    if(n%2 == 1){
	        matriz[n/2][n/2] = (n/2)+1;
	    }
	
	    for(posicao1 = 0; posicao1 < n; posicao1++){
	        for(posicao2 = 0; posicao2 < n; posicao2++){
	            if(posicao2 == 0){
	                printf("%3d", matriz[posicao1][posicao2]);    
	            }else{
	                printf(" %3d", matriz[posicao1][posicao2]);
	            }
	            
	        }
	        printf("\n");
	    }
	
		printf("\n");
	
	}
	
  

    return 0;
}
