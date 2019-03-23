#include <stdio.h>
int main(){
	int k,i,n,j,vet[51],vetD[49];
	
	while(scanf("%d", &n) != 0 && n != 0){
		for(i = 1; i <= n; i++){
			vet[i-1] = i;
		}
		n-=1;
		for(j = 0, k = n; j < n ; j++, k--){
			vetD[j] = vet[0];
		
			vet[k+1] = vet[1];
			for(i = 0; i < n; i++){
				vet[i] = vet[i+2];
			}
		}
		printf("Discarded cards: %d", vetD[0]);
		for(i = 1; i < n; i++){
			printf(", %d", vetD[i]);
		}
		printf("\nRemaining card: %d\n", vet[0]);
	}
	return 0;
}
