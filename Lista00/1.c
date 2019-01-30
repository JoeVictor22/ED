#include <stdio.h>
//input 		100 200 1 3 5 4 2 5 6 3
int main(){

	int lista[10];
	int i = 0, j, valor,quantImparesMedia = 0,mediaImpares = 0,quantPares = 0;
	printf("Insira uma lista de ate 100 numeros menores que 256\n");
	printf("Pressione 'CONTROL + D' para encerrar a leitura.\n");
	while (scanf("%d", &lista[i]) != EOF || lista[i] == '\n') {
		if (lista[i] < 256) {

			if (lista[i] % 2 == 1) {
				if(lista[i] > 50)
				mediaImpares = mediaImpares + lista[i];
				quantImparesMedia++;
				printf("\nqndt eh %d, %d", mediaImpares, quantImparesMedia);
			}
			else {
				quantPares++;
			}

			valor = lista[i];
			j = i - 1;

			while (j >= 0 && valor > lista[j]) {
				lista[j + 1] = lista[j];
				j--;
			}
			lista[j + 1] = valor;

			i++;
			if (i == 10)
				break;
		}

		
		
	}

	for (int j = 0; j < i; j++) {
		printf("%d ", lista[j]);
	}

	mediaImpares = mediaImpares / quantImparesMedia;
	printf("A media entre os numeros impares maiores que 50 eh %d\n", mediaImpares);

	printf("Existem %d numeros pares e %d numeros impares\n", quantPares, i - quantPares);

	printf("terminou");

	return 0;
}
