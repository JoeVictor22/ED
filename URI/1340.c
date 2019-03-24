#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pilha{
    int topo;
    int *elementos;
};

struct fila{
    int front;
    int size;
    int *elementos;
};
struct filaP{
	int topo;
	int *elementos;
};

//pilha
void createPilha(struct pilha *p);
int pop(struct pilha *p);
void push(struct pilha *p, int elemento);
bool isEmptyPilha(struct pilha *p);
void printPilha(struct pilha *p);
void liberarPilha(struct pilha *p);
//FILA
void createFila(struct fila *f);
int popFront(struct fila *f);
void add(struct fila *f, int elemento);
bool isEmptyFila(struct fila *f);
void printFila(struct fila *f);
void liberarFila(struct fila *f);
//PRIORIDADE
void createFilaP(struct filaP *f);
int popP(struct filaP *f);
void pushP(struct filaP *f, int elemento);
bool isEmptyFilaP(struct filaP *f);
void printFilaP(struct filaP *f);
void liberarFilaP(struct filaP *f);

int main(){

    struct fila f;
    struct pilha p;
    struct filaP fp;
	int i, opc, x,n ;
    bool pilha, fila, filaP;

	createPilha(&p);
	createFila(&f);
	createFilaP(&fp);
	
    while(scanf("%d", &n) != EOF){
    	fila = true;
    	pilha = true;
    	filaP = true;
        for(i = 0; i < n; i++){
            scanf("%d", &opc);
            scanf("%d", &x);
            switch(opc){
               
                case 1:
                    push(&p, x);
                    add(&f, x);
                    pushP(&fp, x);
                    break;
                case 2:

                    if(x != pop(&p)){
                        pilha = false;
                    }
                    if(x != popFront(&f)){
					    fila = false;
                    }
                    if(x != popP(&fp)){
                        filaP = false;
                    }
                    break;
                default:
                    break;
            }
		
        }
        
        
        if(pilha){
            if(( fila || filaP)){
                printf("not sure\n");
            }else{
                printf("stack\n");
            }
        }else if(fila){
            if((filaP)){
                printf("not sure\n");
            }else{
                printf("queue\n");
            }
        }else if(filaP){
            printf("priority queue\n");
        }else{
            printf("impossible\n");
        }
        
        liberarPilha(&p);
        liberarFila(&f);
        liberarFilaP(&fp);
        
    }

    
	
    return 0;
}

//PILHA
void createPilha(struct pilha *p){
    p->topo = -1;
    p->elementos = (int*)malloc(1 * sizeof(int));
}

int pop(struct pilha *p){
    if(isEmptyPilha(p)){
        printf("Está vazia, retornando 0\n");
        return 0;
    }else{
        return p->elementos[p->topo--];
    }
}
void push(struct pilha *p, int elemento){
    p->topo++;
    int *aux = (int*)realloc(p->elementos, (p->topo+1) * sizeof(int));
    if(aux == NULL){
        printf("ERRO\n");
        exit(0);
    }else{
        p->elementos = aux;
        p->elementos[p->topo] = elemento;
    }
}
bool isEmptyPilha(struct pilha *p){
    if(p->topo == -1){
        return true;
    }else{
        return false;
    }
}
void printPilha(struct pilha *p){
   
    if(isEmptyPilha(p)){
        printf("Está vazia\n");
    }else{
        int i;
	    for(i = 0; i < p->topo; i++){
	        printf(" %d,", p->elementos[i]);
	    }
	    printf(" %d\n", p->elementos[p->topo]);
    }
}
void liberarPilha(struct pilha *p){
	free(p->elementos);
    p->topo = -1;
    p->elementos = (int*)malloc(1 * sizeof(int));
}


//FILA
void createFila(struct fila *f){
    f->size = 0;
    f->front= 0;
    f->elementos = (int*)malloc(1 * sizeof(int));
}
int popFront(struct fila *f){
    if(isEmptyFila(f)){
        printf("Está vazia, retornando 0\n");
        return 0;
    }else{
        return f->elementos[f->front++];
    }

}
void add(struct fila *f, int elemento){
    f->size += 1; 
    int i,*aux = (int*)realloc(f->elementos, (f->size) * sizeof(int));
    if(aux == NULL){
        printf("ERRO\n");
        exit(0);
    }else{
        f->elementos = aux; 
        f->elementos[f->size-1] = elemento;
    }
        
}

bool isEmptyFila(struct fila *f){
    if(f->front == f->size){
        return true;
    }else{
        return false;
    }
}

void printFila(struct fila *f){
  
    if(isEmptyFila(f)){
        printf("Está vazia\n");
    }else{
        int i;
   		for(i = f->front; i < f->size; i++){
       		printf(" %d,", f->elementos[i]);
    	}
    }

}
void liberarFila(struct fila *f){
	free(f->elementos);
    f->size = 0;
    f->front= 0;
    f->elementos = (int*)malloc(1 * sizeof(int));
}

//PRIORIDADE
void createFilaP(struct filaP *f){
	f->topo = -1;
	f->elementos = (int*)malloc(1* sizeof(int));
}
int popP(struct filaP *f){
    if(isEmptyFilaP(f)){
        printf("Está vazia, retornando 0\n");
        return 0;
    }else{
        return f->elementos[f->topo--];
    }
}
void pushP(struct filaP *f, int elemento){
    f->topo++;
    int i;
    int *aux = (int*)realloc(f->elementos, (f->topo+1) * sizeof(int));
    if(aux == NULL){
        printf("ERRO\n");
        exit(0);
    }else{
        f->elementos = aux;
        i = f->topo-1;
        while((i >= 0 )&& (f->elementos[i] > elemento )) {
        	
        	f->elementos[i+1] = f->elementos[i]; 
        	i--;
		}
        f->elementos[i+1] = elemento;
    }
}

bool isEmptyFilaP(struct filaP *f){
    if(f->topo == -1){
        return true;
    }else{
        return false;
    }
}
void printFilaP(struct filaP *f){
   
    if(isEmptyFilaP(f)){
        printf("Está vazia\n");
    }else{
        int i;
	    for(i = 0; i < f->topo; i++){
	        printf(" %d,", f->elementos[i]);
	    }
	    printf(" %d\n", f->elementos[f->topo]);
    }
    printf("\n");
}
void liberarFilaP(struct filaP *f){
	free(f->elementos);
    f->topo = -1;
	f->elementos = (int*)malloc(1* sizeof(int));
}


