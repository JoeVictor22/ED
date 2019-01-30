#include <stdio.h>

int ehPrimo(int numero);

int main() {
	int numero;
	int copia;

	INICIO:
	printf("Digite um numero primo!\n");
	scanf("%d", &numero);

	if (ehPrimo(numero) == 1) {
		printf("ele eh primo\n");

		copia = numero;
		for (int i = 0; i < 2;) {
			copia--;
			if (copia == 1) {
				printf("nao existe mais numeros a esquerda de %d\n", numero);
				break;
			}else if (ehPrimo(copia) == 1) {
				i++;
				printf("O %dº numero primo a esquerda de %d eh %d\n", i, numero, copia);
			}
			
		}

		copia = numero;
		for (int i = 0; i < 2;) {
			copia++;
	
			if (ehPrimo(copia) == 1) {
				i++;
				printf("O %dº numero primo a direita de %d eh %d\n", i, numero, copia);
			}

		}

	}
	else {
		printf("nao eh primo\n");
		goto INICIO;
	}

	return 0;
}

int ehPrimo(int numero) {

	if (numero <= 1) {
		return 0;
	}

	for (int i = 2; i <= numero / 2; i++) {
		if (numero%i == 0) {
			return 0;
		}
	}

	return 1;

}
