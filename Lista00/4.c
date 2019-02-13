#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int numero);

int main() {
	int numero;
	int copia;
	int i;
	int key = false;

	
	while(key == false){
		printf("Digite um numero primo!\n");
		scanf("%d", &numero);

		if(ehPrimo(numero) == true){
			key = true;	
			printf("ele eh primo\n");
	
			copia = numero;
			for (i = 0; i < 2;) {
				copia--;
				if (copia == 1) {
					printf("nao existe mais numeros a esquerda de %d\n", numero);
					break;
				}else if (ehPrimo(copia) == true) {
					i++;
					printf("O %d numero primo a esquerda de %d eh %d\n", i, numero, copia);
				}	
			}
	
			copia = numero;
			for (i = 0; i < 2;) {
				copia++;
		
				if (ehPrimo(copia) == true) {
					i++;
					printf("O %d numero primo a direita de %d eh %d\n", i, numero, copia);
				}
	
			}
		}else{
			printf("nao eh primo\n");
		}
	}
	return 0;
}

bool ehPrimo(int numero) {

	if (numero <= 1) {
		return false;
	}
	int i;
	for ( i = 2; i <= numero / 2; i++) {
		if (numero%i == 0) {
			return false;
		}
	}

	return true;

}
