#include <stdio.h>
#include <stdlib.h>

char m[50][50]; //matriz variavel global, nao precisa declarar nas funcoes

struct info{
char pergunta[50];
int orientacao;
int lugar1;
int lugar2;
};

int main()
{
int n;
int i, j;

for(i=1; i<50; i++){ //define os espaços vazios da matriz
        for(j=1; j<50; j++){
            m[i][j] = '-';
        }}

impressora(m);

printf("Quantas palavras quer utilizar ?\n");
scanf("%d", &n);

while(n != 0){ //vai rodar o mesmo tanto que a quantidade de palavras solicitado

    preencher_matriz();

    n = n - 1;
}

impressora(m);

}

void impressora(char mat[50][50]){
    int i=0,j=0;
    for(i=0; i<50; i++){ //imprime a matriz
        for(j=0; j<50; j++){
            printf("%2c", mat[i][j]);
        }
            printf("\n");
        }
}


void preencher_matriz(){

struct info p;
char resposta[10]; //nao esta dentro do struct pensando na alocacao dinamica
//int lugar1
//int lugar2
//int orienta

int i, j, k;

//printf("pergunta:\n");
//scanf("%s", p.pergunta);

printf("resposta:\n");
scanf("%s", resposta);

printf("orientacao:\n");
scanf("%d", &p.orientacao);

printf("lugar:\n");
scanf("%d", &p.lugar1);
scanf("%d", &p.lugar2);

if(p.orientacao == 1){ //vertical

    j = p.lugar2;

    for(i=p.lugar1, k=0 ; i<(p.lugar1 + 10) , k < 10; i++ , k++){
        m[i][j] = resposta[k];
        }
}

if(p.orientacao == 2){  //horizontal

 i = p.lugar2; 

    for(j=p.lugar1, k=0 ; j<(p.lugar1 + 10) , k < 10; j++ , k++){
        m[i][j] = resposta[k];
        }
}

}
