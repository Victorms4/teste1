#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct no
{
    struct no *ant;
    char dado[15];
    int numero;
    int ordem;
    struct no *prox;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;
} listade;

void cria(listade *q);
int  insere(listade *q, char d[]);
int  retira(listade *q, int o);

void transforma(listade *q);
void numerosComZero();
void limpaLista(listade *q);

listade lista;
int fila=0;
int estado=0;

int main(void){

    cria(&lista);
}

void cria(listade *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}

int  insere(listade *q, char d[])
{
    struct no *aux;
    aux = (struct no*) malloc(sizeof(struct no));
    if (aux == NULL)
        return 0;
    if (q->inicio == NULL)
    {
        aux->dado = d;
        q->inicio = aux;
        q->fim = aux;
        return 1;
    }
    aux->dado = d;
    aux->ant = q->fim;
    q->fim->prox = aux;
    aux->prox = NULL;
    q->fim = aux;

    aux->numero = 0;
    aux->ordem = fila;
    fila++;
    return 1;
}

int retira(listade *q, int o)
{
    struct no *aux, *anterior, *atual;
    if (q->inicio == NULL)
        return 0;
    // remover o primeiro n  de uma lista unit ria��
    if (q->inicio == q->fim && o == q->inicio->ordem)
    {
        aux = q->inicio;
        q->inicio = NULL;
        q->fim = NULL;
        free(aux);
        return 1;
    }
    // remover o primeiro de uma lista n o unit ria��
    if (q->inicio != q->fim && o == q->inicio->ordem)
    {
        aux = q->inicio;
        q->inicio = q->inicio->prox;
        free(aux);
        return 1;
    }
    // remover o  ltimo n  da lista��
    if (q->fim->ordem == o)
    {
        aux = q->fim;
        q->fim = q->fim->ant;
        free(aux);
        return 1;
    }
    // remover um n  no meio da lista�
    printf("Processando o no com dado = %d\n", q->inicio->ordem);
    anterior = q->inicio;
    atual = q->inicio->prox;
    while (atual->ordem != o && atual != q->inicio)
    {
        printf("Processando o no com dado = %d\n", atual->ordem);
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == q->inicio)
    {
        printf("\nDado %d nao existe na lista...\n", o);
        return 0;
    }
    else
    {
        printf("Dado %d encontrado e sera removido...\n", atual->ordem);
        aux = atual;
        anterior->prox = atual->prox;
        atual->prox->ant = anterior;
        free(aux);
        return 1;
    }
}

void transforma(listade *q){
    struct no *aux;
    aux = q->inicio;
    //Primeira passagem pela lista: Identificar os números
    while(aux != NULL){
        if(strcmp(aux->dado, "um")==0)
            aux->numero = 1;
        if(strcmp(aux->dado, "dois")==0)
            aux->numero = 2;
        if(strcmp(aux->dado, "tres")==0)
            aux->numero = 3;
        if(strcmp(aux->dado, "quatro")==0)
            aux->numero = 4;
        if(strcmp(aux->dado, "cinco")==0)
            aux->numero = 5;
        if(strcmp(aux->dado, "seis")==0)
            aux->numero = 6;
        if(strcmp(aux->dado, "sete")==0)
            aux->numero = 7;
        if(strcmp(aux->dado, "oito")==0)
            aux->numero = 8;
        if(strcmp(aux->dado, "nove")==0)
            aux->numero = 9;
        if(strcmp(aux->dado, "dez")==0)
            aux->numero = 10;
        if(strcmp(aux->dado, "onze")==0)
            aux->numero = 11;
        if(strcmp(aux->dado, "doze")==0)
            aux->numero = 12;
        if(strcmp(aux->dado, "treze")==0)
            aux->numero = 13;
        if(strcmp(aux->dado, "quatorze")==0 || strcmp(aux->dado, "catorze")==0)
            aux->numero = 14;
        if(strcmp(aux->dado, "quinze")==0)
            aux->numero = 15;
        if(strcmp(aux->dado, "dezesseis")==0)
            aux->numero = 16;
        if(strcmp(aux->dado, "dezessete")==0)
            aux->numero = 17;
        if(strcmp(aux->dado, "dezoito")==0)
            aux->numero = 18;
        if(strcmp(aux->dado, "dezenove")==0)
            aux->numero = 19;
        if(strcmp(aux->dado, "vinte")==0)
            aux->numero = 20;
        if(strcmp(aux->dado, "trinta")==0)
            aux->numero = 30;
        if(strcmp(aux->dado, "quarenta")==0)
            aux->numero = 40;
        if(strcmp(aux->dado, "cinquenta")==0)
            aux->numero = 50;
        if(strcmp(aux->dado, "sessenta")==0)
            aux->numero = 60;
        if(strcmp(aux->dado, "setenta")==0)
            aux->numero = 70;
        if(strcmp(aux->dado, "oitenta")==0)
            aux->numero = 80;
        if(strcmp(aux->dado, "noventa")==0)
            aux->numero = 90;
        if(strcmp(aux->dado, "cem")==0)
            aux->numero = 100;
        if(strcmp(aux->dado, "duzentos")==0)
            aux->numero = 200;
        if(strcmp(aux->dado, "trezentos")==0)
            aux->numero = 300;
        if(strcmp(aux->dado, "quatrocentos")==0)
            aux->numero = 400;
        if(strcmp(aux->dado, "quinhentos")==0)
            aux->numero = 500;
        if(strcmp(aux->dado, "seiscentos")==0)
            aux->numero = 600;
        if(strcmp(aux->dado, "setecentos")==0)
            aux->numero = 700;
        if(strcmp(aux->dado, "oitocentos")==0)
            aux->numero = 800;
        if(strcmp(aux->dado, "novecentos")==0)
            aux->numero = 900;
        aux = aux->prox;
    }

    aux = q->inicio;
    while(aux != NULL){
        if(strcmp(aux->dado, "mil")==0){
            aux->numero = 1000;
            if(aux->ant != NULL){
                aux = aux->ant;
                numerosComZero(aux, 1000);
            }
        }
        if(strcmp(aux->dado, "milhao")==0 || strcmp(aux->dado, "milhoes")==0){
            if(aux->ant == NULL){
                printf("Erro encontrado. Tente Novamente...");
                estado = 1;
            }
            else{
                aux = aux->ant;
                numerosComZero(aux, 1000000);
            }
        }
        if(strcmp(aux->dado, "bilhao")==0 || strcmp(aux->dado, "bilhoes")==0){
            if(aux->ant == NULL){
                printf("Erro encontrado. Tente Novamente...");
                estado = 1;
            }
            else{
                aux = aux->ant;
                numerosComZero(aux, 1000000000);
            }
        }
        if(strcmp(aux->dado, "e")){
            aux->ant->numero = aux->ant->numero + aux->prox->numero;
            aux = aux->ant;
            retira(q, aux->prox->ordem);
            retira(q, aux->prox->ordem);
        }
        aux = aux->prox;
    }
    if(estado == 1){
        limpaLista(q);
    }
}

void numerosComZero(struct no *aux, int n){
    if(n == 1000 && aux->numero == 0)
        return;
    if(aux->numero == 0 || aux->ant == NULL){
        printf("Erro encontrado tente novamente...");
        estado = 1;
        return;
    }
    aux->numero = aux->numero * n;
    retira(&lista, aux->prox->ordem);
    return;
}

void limpaLista(listade *q){
    while(q->inicio != NULL && q-> fim != NULL){
        retira(q, q->inicio->ordem);
    }
}
