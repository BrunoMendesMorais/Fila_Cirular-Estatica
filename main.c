#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct{
	int dados[MAX];
	int inicio;
	int fim;
	int quantidade;
}FilaCircular;

void fim(){
	getchar();
	printf("\n\nprecione enter para continuar");
	getchar();
	system("cls");
}

void adicionar(FilaCircular *f,int num){
	f->fim = (f->fim+1)%MAX;
	f->dados[f->fim] = num;
	f->quantidade++;
	fim();
}

void remover(FilaCircular *f){
	if(f->quantidade == 0){
		printf("Fila vazia");
		return;
	}
	f->quantidade--;
	f->inicio = (f->inicio +1)%MAX;
	fim();
}

void ler(FilaCircular *f){
	if(f->quantidade == 0){
		printf("Fila vazia");
		return;
	}
	int i;
	for (i=0;i<f->quantidade;i++){
		printf("%d ",f->dados[(f->inicio+i)%MAX]);
	}
	fim();
}

void buscar(FilaCircular *f,int n){
	int i;
	if(f->quantidade == 0){
		printf("Fila vazia");
		return;
	}
	for (i=0;i<f->quantidade;i++){
		if(f->dados[(f->inicio+i)%MAX] == n){
			printf("numero %d encontrado",n);
			return;
		}
	}
	printf("numero %d não encontrado",n);
	fim();
}

int main(int argc, char *argv[]) {
	int num, op, o = 0;
	FilaCircular f;
	f.fim = -1;
	f.inicio = 0;
	f.quantidade = 0;
	while(o == 0){
		printf("Escolha a opcao desejada:\n\n-[1] Adicionar\n-[2] Retirar\n-[3] Exibir fila\n-[4] Buscar\n\nPrecione outro numero para sair");
		scanf("%d",&op);
		switch(op){
			case 1:
				if(f.quantidade == MAX){
					system("cls");
					printf("numero max atingido");
					fim();
					break;
				}
				system("cls");
				printf("\nNumero que deseja adicionar: ");
				scanf("%d",&num);
				adicionar(&f,num);
				break;
			case 2:
				system("cls");
				if(f.quantidade == 0){
					printf("\nFila esta vazia");
					fim();
					break;
				}
				remover(&f);
				printf("\nPrimeiro elemento retirado com sucesso");
				break;
			case 3:
				system("cls");
				if(f.quantidade == 0){
					printf("\nFila esta vazia");
					fim();
					break;
				}
				ler(&f);
				break;
			case 4:
				system("cls");
				if(f.quantidade == 0){
					printf("\nFila esta vazia");
					fim();
					break;
				}
				printf("\nNumero que deseja verficar se esta na fila: ");
				scanf("%d",&num);
				buscar(&f,num);
				break;
			default:
				o = 1;
		}
	}
	return 0;
}
