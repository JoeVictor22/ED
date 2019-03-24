#include <stdio.h>
#include <stdbool.h>

struct pilha{
    int topo;
    int *elementos;
};

void create(struct pilha *p);
int pop(struct pilha *p);
void push(struct pilha *p, int elemento);
bool isEmpty(struct pilha *p);
void print(struct pilha *p);
void liberar(struct pilha *p);

int main(){

    struct pilha p;
    struct pilha descartadas;
    int i,n;

    scanf("%d", &n);
    while(n != 0){
		create(&p);
	    create(&descartadas);

        for(i = n; i >= 1;i--){

		    push(&p, i);
        }
        while(p.topo > 0){
            push(&descartadas, pop(&p));
            pushToFront(&p, pop(&p));
        }
        printf("Discarded cards:");
        print(&descartadas);
		printf("Remaining card: %d\n", p.elementos[0]);
		liberar(&p);
		liberar(&p);
    
        scanf("%d", &n);
    }

    return 0;
}


void create(struct pilha *p){
    p->topo = -1;
    p->elementos = (int*)malloc(1 * sizeof(int));
}

int pop(struct pilha *p){
    if(isEmpty(p)){
        printf("Está vazia\n");
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
void pushToFront(struct pilha *p, int elemento){
    p->topo++;
    int i,*aux = (int*)realloc(p->elementos, (p->topo+1) * sizeof(int));
    if(aux == NULL){
        printf("ERRO\n");
        exit(0);
    }else{
        p->elementos = aux;
        for(i = p->topo; i > 0; i--){
            p->elementos[i] = p->elementos[i-1];    
        }
        p->elementos[0] = elemento;
    }
    
}

bool isEmpty(struct pilha *p){
    if(p->topo == -1){
        return true;
    }else{
        return false;
    }
}

void print(struct pilha *p){
    int i;
    for(i = 0; i < p->topo; i++){
        printf(" %d,", p->elementos[i]);
    }
    printf(" %d\n", p->elementos[p->topo]);
}

void liberar(struct pilha *p){
	free(p->elementos);
}
