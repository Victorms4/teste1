#include <stdio.h>
#include <stdlib.h>


struct no
{
    struct no *ant;
    char dado[15];
    int numero=0;
    struct no *prox;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;
} listade;

void cria(listade *q);
int  insere(listade *q, char d[]);
void transforma();
void remocaoDez();

int main(void){
    listade lista;

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
    return 1;
}

void transforma(){
    struct no *aux;
    aux = q->inicio;
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
        if(strcmp(aux->dado, "mil")==0){
            aux->numero = 1000;
            remocaoDez(aux, 1000);
        }
        if(strcmp(aux->dado, "milhao")==0 || strcmp(aux->dado, "milhoes")==0){
            aux->numero = 1000000;
            remocaoDez(aux, 1000000);
        }
        if(strcmp(aux->dado, "bilhao")==0 || strcmp(aux->dado, "bilhoes")==0){
            aux->numero = 1000000000;
            remocaoDez(aux, 1000000000);
        }
    }
}

void remocaoDez(struct no *aux, int n){
    if(numero == 1000 && aux->ant->numero == 0)
        return;
    if(aux->ant->numero == 0 || aux->ant == NULL){
        printf("Erro encontrado tente novamente...");
        return;
    }
    aux->ant->numero = aux->ant->numero * n;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    return;
}
