#include <stdio.h>

void limpa();
float adicao(float, float);
float subtracao(float, float);
float multiplicacao(float, float);
float divisao(float, float);

int main(void){

    float a,b,c;
    char op, continuar;
    unsigned short int flag=1;

    printf("Calculadora Simples de Quatro Operações\n");
    printf("|-------------------------------------|\n\n");

    do{

    printf("\nDigite o primeiro valor:");
    scanf("%f", &a);
    getchar();

    printf("\nDigite o segundo valor:");
    scanf("%f", &b);
    getchar();

    printf("\nEscolha o operador(+ - * /):");
    op = getchar();
    getchar();

    switch(op){
    case '+':
        c = a + b;
        break;
    case '-':
        c = a - b;
        break;
    case '*':
        c = a * b;
        break;
    case '/':
        if(b !=0)printf("\nDigite o primeiro valor:");
    scanf("%d", &a);
    getchar();

    printf("\nDigite o segundo valor:");
    scanf("%d", &b);
    getchar();

    printf("\nEscolha o operador(+ - * /):");
    op = getchar();
    getchar();

    switch(op){
    case '+':
        c = adicao(a, b);
        break;
    case '-':
        c = subtracao(a, b);
        break;
    case '*':
        c = multiplicacao(a, b);
        break;
    case '/':
        if(b !=0)
            c = divisao(a, b);
        break;
    default:
        printf("%c é um operador inválido", op);
        flag = 0;
    }

    if(flag){
        if(op == '/' && b == 0)
            printf("\nDivisão por zero");
        else
            printf("\nResultado da operação %.2f %c %.2f %.2f", a, op, b, c);
    }

    printf("\nCalcular novamente?(s/n)");
    continuar = getchar();
    getchar();
    flag = 1;
            c = a + b;
        break;
    default:
        printf("%c é um operador inválido", op);
        flag = 0;
    }

    if(flag){
        if(op == '/' && b == 0)
            printf("\nDivisão por zero");
        else
            printf("\nResultado da operação %.2f %c %.2f %.2f", a, op, b, c);
    }

    printf("\nCalcular novamente?(s/n)");
    continuar = getchar();
    getchar();
    flag = 1;
    limpa();
    }while(continuar == 's');

    return 0;
}

void limpa(){
    printf("\033[H\033[J");
    return;
}

float adicao(float a, float b){
    return a + b;
}

float subtracao(float a, float b){
    return a - b;
}

float multiplicacao(float a, float b){
    return a * b;
}

float divisao(float a, float b){
    return (a / b);
}
