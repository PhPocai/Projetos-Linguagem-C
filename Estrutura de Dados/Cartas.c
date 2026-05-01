#include <stdio.h>
#include <stdlib.h>
#include <String.h>

typedef struct CARTAS{
    int valor;
    char naipe[10];
}cartas;

int conta_valor (int valor,cartas *v, int n_elementos){
    int i,contador=0;
    for(i=0;i<n_elementos;i++){
       if(v[i].valor == valor) contador++;
    }

    return contador;
}

void recebe_cartas (int num, char np[],cartas *v, int *n_elementos){
    cartas aux;
    int i;
    if((*n_elementos < 20) && (num>=1 && num<=13) && conta_valor (num,v,*n_elementos) < 4 ){
         v[*n_elementos].valor=num;
        strcpy(v[*n_elementos].naipe,np);
        i=*n_elementos;
        while(i>0 && v[i].valor < v[i-1].valor){
            aux=v[i];
            v[i]=v[i-1];
            v[i-1] = aux;
            i--;
        }
        (*n_elementos)++;
    }

    else printf("Numero maximo de cartas atingido");
}

void ver_lista_cartas(cartas *v, int *n_elementos){
    int i;
    printf("\n");
    for(i=0;i<*n_elementos;i++){
        printf("%d %s\n",v[i].valor,v[i].naipe);
    }

}

void remover_carta (int num, char np[],cartas *v, int *n_elementos){
    int i, pos = -1;
    for(i = 0; i < *n_elementos; i++){
        if(v[i].valor == num && strcmp(v[i].naipe, np) == 0){
            pos = i;
            break;
        }
    }
    if(pos != -1){
        for(i = pos; i < *n_elementos-1; i++){
            v[i] = v[i+1];
        }
        (*n_elementos)--;
    }
}

void exibe_trincas(cartas *v, int *n_elementos){
     int i = 0;
     for(i=0;i<*n_elementos-2;i++){
      if(v[i].valor == v[i+1].valor && v[i].valor == v[i+2].valor){

            printf("\nTrinca encontrada:\n");
            printf("%d %s\n", v[i].valor, v[i].naipe);
            printf("%d %s\n", v[i+1].valor, v[i+1].naipe);
            printf("%d %s\n", v[i+2].valor, v[i+2].naipe);
        }
     }
}

int main()
{
    cartas vet [20];
    int n_elementos = 0,opcao=-1;
    int valor_remover;
    char naipe_remover[10];
    printf("Jogo de cartas\n");
    printf("================\n");
    recebe_cartas(1,"Copas",vet,&n_elementos);
    recebe_cartas(1,"Paus",vet,&n_elementos);
    recebe_cartas(1,"Espadas",vet,&n_elementos);
    recebe_cartas(5,"Copas",vet,&n_elementos);
    recebe_cartas(3,"Copas",vet,&n_elementos);
    recebe_cartas(11,"Espadas",vet,&n_elementos);
    recebe_cartas(7,"Ouros",vet,&n_elementos);
    recebe_cartas(1,"Paus",vet,&n_elementos);
    recebe_cartas(9,"Copas",vet,&n_elementos);
    recebe_cartas(13,"Espadas",vet,&n_elementos);
    recebe_cartas(4,"Ouros",vet,&n_elementos);
    recebe_cartas(6,"Paus",vet,&n_elementos);
    recebe_cartas(10,"Copas",vet,&n_elementos);
    recebe_cartas(2,"Espadas",vet,&n_elementos);
    recebe_cartas(8,"Ouros",vet,&n_elementos);
    recebe_cartas(12,"Paus",vet,&n_elementos);
    recebe_cartas(5,"Copas",vet,&n_elementos);
    recebe_cartas(7,"Espadas",vet,&n_elementos);
    recebe_cartas(9,"Ouros",vet,&n_elementos);

    printf("Selecione a acao desejada:\n");
    while(opcao != 0){
    printf(" \n 1 - Ver lista de cartas \n 2-Remover carta \n 3-Exibir Trincas\n 0-Sair \n");
    scanf("%d",&opcao);
        switch(opcao){
        case 1:
            ver_lista_cartas(vet,&n_elementos);
            break;
        case 2:
            printf("\nInforme o numero e naipe da carta:\n");
            scanf("%d %s",&valor_remover,naipe_remover);
            remover_carta(valor_remover,naipe_remover,vet,&n_elementos);
            ver_lista_cartas(vet,&n_elementos);
            break;
        case 3:
            exibe_trincas(vet,&n_elementos);
            break;
        case 0:
            printf("\nFim");
            return 0;
            break;
        }
    }

    return 0;
}
