#include <stdio.h>

long long int fib(long long int x);

long long int vtFib[10000];

int main(){
	
	long long int x;
	
	for(x = 0; x < 100; vtFib[x] = 0,x++){
	}
    	int n;
	scanf("%d", &n);

	while(n){
	
		scanf("%lli", &x);

		printf("Fib(%lli) = %lli\n", x, fib(x));

		n--;
  	}


	return 0;
}


long long int fib(long long int x){
	long long int i;

	if(vtFib[x-1] != 0){
		return vtFib[x-1];
	}else{ 
		if(x <= 2){
			if(x == 0){
				return 0;
			}else{
			return 1;	
			}
		}else{
			vtFib[x-1] = fib(x-1) + fib(x-2);
			return vtFib[x-1];
		}
	}

	return x;
}
