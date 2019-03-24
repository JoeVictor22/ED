#include <stdio.h>
#include <stdbool.h>
struct riacho{
    int inicio;
    long fim;
    long presente;
};

bool saltarEsquerda(struct riacho *r, long posicao, long salto);
bool saltarDireita(struct riacho *r, long posicao, long salto);

int main(){

    struct riacho r;
    r.inicio = 1;

	scanf("%d %d", &r.fim,&r.presente);		
    while(r.fim != 0 && r.presente != 0){

		if(r.presente > 34){
			printf("Let me try!\n");
		}else{	
			if(saltarEsquerda(&r, 1, 3) || saltarDireita(&r,1, 3)){
	        	printf("Let me try!\n");
	    	}else{
	        	printf("Don't make fun of me!\n");
		    }		
		}
	    scanf("%d %d", &r.fim,&r.presente);
	}

    return 0;
}

bool saltarEsquerda(struct riacho *r, long posicao, long salto){
    if(posicao < r->inicio){
		return false;
    }else if(posicao == r->presente){
		return true;
    }
 	return saltarEsquerda(r, posicao-salto, salto+2) || saltarDireita(r, posicao+salto, salto+2);
}

bool saltarDireita(struct riacho *r, long posicao, long salto){
    if(posicao > r->fim){
		return false;
    }else if(posicao == r->presente){
		return true;
	}
  	return saltarEsquerda(r, posicao-salto, salto+2) || saltarDireita(r, posicao+salto, salto+2);
}
