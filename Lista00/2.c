#include <stdio.h>

int main(){

	int n;

	printf("Digite o tamanho do vetor:\n");

	do {
		scanf("%d", &n);
	} while (n <= 0);
	
	int x[n];
	int y[n];

	printf("Digite os %d elementos que compoem o vetor:\n", n);


	scanf("%d", &x[0]);
	int maior = x[0];
	int menor = x[0];

	for(int i = 1; i < n; i++){
		scanf("%d", &x[i]);

		if(x[i] > maior)
			maior = x[i];
		else if(x[i] < menor)
			menor = x[i];
	}

	int j = 0;
	for (int i = 0; i < n;i++) {
		if (x[i] <= 40 && x[i] >= 10) {
			y[j] = x[i];
			j++;
			printf("eh %d\n", y[j - 1]);
		}

	}

	int w[n/2];
	for (int i = 1, s = 0 ; i < n; i+=2, s++){
		w[s] = x[i];

	}

	printf("O vetor digitado foi:\n");
	for(int i = 0; i < n; i++){
		printf("%d ", x[i]);
	}

	printf("\nO vetor com numeros entre 10 e 40 eh:\n");
	printf("J eh igual %d\n", j);
	for (int i = 0; i < j; i++) {
		printf("%d ", y[i]);
	}
	


	printf("\nO vetor de numeros em posicoes pares eh:\n");
	for(int i = 0; i < n/2; i++){
		printf("%d ", w[i]);
	}

	printf("\nO maior numero foi %d e o menor foi %d\n", maior, menor);

	printf("\nDigite um numero para procura-lo no vetor:\n");
	int z;
	scanf("%d", &z);
	
	short int existe = 0;
	int i;
	for(i = 0 ; i < n && existe == 0; i++){
		if(x[i] == z){
			existe = 1;
		}
	}
	if(existe == 1){
		printf("O numero %d está na posicao %d do vetor.\n",z,i);
	}else{
		printf("O numero %d não existe no vetor.\n",z);
	}
    return 0;
}
